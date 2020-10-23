#!/bin/bash

CURDIR=`/bin/pwd`

# Target the makefile to be configurated. 
read -p "Target Directory: " -i "$CURDIR/" -e targetDirectory
targetMakefile=$targetDirectory"Makefile"
echo "Choosen Makefile : $targetMakefile"


#makefileconf for makefile path
targetMakefileConf="makefile.conf"

#Backup that would be made only once if not deleted by hand.
BACKUP_FILE=$targetMakefile".backup"

# Inclueding the makefile.conf common for all Makefiles 
TO_INCLUDE='include ../../makefile.conf'

# Specs Flags are the ones to be modified to compile C or CPP file Plese refer to makefile.conf for more infomration
ANCHOR_SPECS_FLAG='-specs=nano.specs'
SPECS_FLAG='$(SPECS_FLAG)'
ARRAY_OF_ANCHORS[0]=$ANCHOR_SPECS_FLAG

# TARGET defines the name of the project for STMCUBE 
ANCHOR_TARGET='TARGET = '
TARGET_NAME='TARGET = $(APPLICATION_NAME)'
ARRAY_OF_ANCHORS[1]=$ANCHOR_TARGET

# Build dir, as the name implise is were the builded file would go to to
ANCHOR_BUILD_DIR='BUILD_DIR = ' # The space at the end is important 
BUILD_DIR_NEW='BUILD_DIR = $(APPLICATION_DIR)' 
ARRAY_OF_ANCHORS[2]=$ANCHOR_BUILD_DIR

# Add custom compilator links for CPP. Please refer to the STMCUBE generated Makefile
ANCHOR_CPP_PREFIX_CUST='CC = $(GCC_PATH)' 
CPP_PREFIX_CUST='CPP = $(GCC_PATH)/$(PREFIX)g++'
ARRAY_OF_ANCHORS[3]=$ANCHOR_CPP_PREFIX_CUST

# Add compilator links fo CPP. Please refer to the STMCUBE generated Makefile
ANCHOR_CPP_PREFIX_DEF='CC = $(PREFIX)gcc' 
CPP_PREFIX_DEF='CPP = $(PREFIX)g++'
ARRAY_OF_ANCHORS[4]=$ANCHOR_CPP_PREFIX_DEF

# Object array push for CPP objects. Please refer to the STMCUBE generated Makefile
ANCHOR_C_OBJECTS='vpath %.c ' #the pasce is important
CPP_OBJECTS_COMMENT='# list of CPP objects'
CPP_OBJECTS_ADD='OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))'
CPP_OBJECTS_VPATH='vpath %.cpp $(sort $(dir $(CPP_SOURCES)))'
ARRAY_OF_ANCHORS[5]=$ANCHOR_C_OBJECTS

# Compilation command for CPP objects. Please refer to the STMCUBE generated Makefile
ANCHOR_C_COMPILE='$(CC) -c'
CPP_COMPILE_COMMENT='#CPP build command'
CPP_COMPILE_DIR='$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)'
CPP_COMPILE_BUILD='\\t$(CPP) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@'
ARRAY_OF_ANCHORS[6]=$ANCHOR_C_COMPILE

#Just to add some colours. 
RED='\e[0;31m'
YELW='\e[0;33m'
BLUE='\e[0;34m'
PRPL='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'
NC='\e[0m'

###############################################################
#making a clean if needed 
###############################################################
make clean

###############################################################
# Cheking for Backup 
###############################################################
if [ -f "$BACKUP_FILE" ]
	then
		echo "Backup exists and will not be replaced" 
	else
		cp $targetMakefile $BACKUP_FILE
		echo "Backup $BACKUP_FILE is made" 
fi

###############################################################
# Configuring the makefile.conf 
###############################################################
slashed=$(echo $targetDirectory | sed -e 's/\//\\\//g')
sed -i "s/^MCU_MAKE_DIR = .*$/MCU_MAKE_DIR = $slashed/g" "$targetMakefileConf"

###############################################################
# Cheking of the anchors are inside the target MAkefile 
###############################################################
for i in "${ARRAY_OF_ANCHORS[@]}"
do
string=$i
	if [ "$string" == "$ANCHOR_SPECS_FLAG" ] # Special check for the only varibe that has been directly substitued.  
	then 
		string=$SPECS_FLAG	
		if grep -qF "$string" $targetMakefile
		then
			echo -e "$PRPL	Anchor : $string Found $NC"
		else
			echo -e "$RED	Anchor : $string Not found -> please check it $NC "
		fi
	else 
		if grep -qF "$string" $targetMakefile
		then
			echo -e "$PRPL	Anchor : $string Found $NC"
		else
			echo -e "$RED	Anchor : $string Not found -> please check it $NC "
		fi
	fi
done

###############################################################
# Replacing / Adding / Modifiying the required Anchors 
###############################################################
sed -i 's///g' $targetMakefile

string=$TO_INCLUDE
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "1 i\\$string" $targetMakefile
fi

string=$SPECS_FLAG
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "s/$ANCHOR_SPECS_FLAG/$SPECS_FLAG/g" $targetMakefile
fi

string=$TARGET_NAME
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "/$ANCHOR_TARGET/a $string" $targetMakefile
	sed -i "/$ANCHOR_TARGET/a # New target name for compilation" $targetMakefile
fi

string=$BUILD_DIR_NEW
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "/$ANCHOR_BUILD_DIR/a $string" $targetMakefile
	sed -i "/$ANCHOR_BUILD_DIR/a # New build dir located on makefile.conf" $targetMakefile
fi

string=$CPP_PREFIX_CUST
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "/$ANCHOR_CPP_PREFIX_CUST/a $string" $targetMakefile
fi

string=$CPP_PREFIX_DEF
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "/$ANCHOR_CPP_PREFIX_DEF/a $string" $targetMakefile
fi

# Be careful with the finding string is the commment that we include and not the replacement.
string=$CPP_OBJECTS_COMMENT
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	sed -i "/$ANCHOR_C_OBJECTS/a $CPP_OBJECTS_VPATH" $targetMakefile
	sed -i "/$ANCHOR_C_OBJECTS/a $CPP_OBJECTS_ADD" $targetMakefile
	sed -i "/$ANCHOR_C_OBJECTS/a $CPP_OBJECTS_COMMENT" $targetMakefile
	sed -i "/$ANCHOR_C_OBJECTS/a # " $targetMakefile
	
	echo "$CPP_OBJECTS_COMMENT	-> Inserted"
	echo "$CPP_OBJECTS_VPATH	-> Inserted"
	echo "$CPP_OBJECTS_ADD	-> Inserted"
fi

# Be careful with the finding string is the commment that we include and not the replacement.
string=$CPP_COMPILE_COMMENT
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	sed -i "/$ANCHOR_C_COMPILE/a $CPP_COMPILE_BUILD" $targetMakefile
	sed -i "/$ANCHOR_C_COMPILE/a $CPP_COMPILE_DIR" $targetMakefile
	sed -i "/$ANCHOR_C_COMPILE/a $CPP_COMPILE_COMMENT" $targetMakefile
	sed -i "/$ANCHOR_C_COMPILE/a # " $targetMakefile
	
	echo "$CPP_COMPILE_COMMENT	-> Inserted"
	echo "$CPP_COMPILE_DIR	-> Inserted"
	echo "$CPP_COMPILE_BUILD	-> Inserted"
fi

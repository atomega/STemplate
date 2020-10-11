#!/bin/bash

RED='\e[0;31m'
YELW='\e[0;33m'
BLUE='\e[0;34m'
PRPL='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'

NC='\e[0m'

TO_INCLUDE='include ../../makefile.conf'

ANCHOR_SPECS_FLAG='-specs=nano.specs'
SPECS_FLAG='$(SPECS_FLAG)'

ANCHOR_BUILD_DIR='BUILD_DIR = build' 
BUILD_DIR_NEW='BUILD_DIR = $(APPLICATION_DIR)' 
BUILD_DIR_COMMENT='# New build dir located on makefile.conf'

ANCHOR_CPP_PREFIX_CUST='CC = $(GCC_PATH)' 
CPP_PREFIX_CUST='CPP = $(GCC_PATH)/$(PREFIX)g++'
ANCHOR_CPP_PREFIX_DEF='CC = $(PREFIX)gcc' 
CPP_PREFIX_DEF='CPP = $(PREFIX)g++'

ANCHOR_C_OBJECTS='vpath %.c ' #the pasce is important
CPP_OBJECTS_COMMENT='# list of CPP objects'
CPP_OBJECTS_ADD='OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))'
CPP_OBJECTS_VPATH='vpath %.cpp $(sort $(dir $(CPP_SOURCES)))'

ANCHOR_C_COMPILE='$(CC) -c'
CPP_COMPILE_COMMENT='#CPP build command'
CPP_COMPILE_DIR='$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)'
CPP_COMPILE_BUILD='\\t$(CPP) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@'

targetMakefile='MCU/G474/Makefile'

sed -i 's///g' $targetMakefile

string=$BUILD_DIR_NEW
if grep -qF "$string" $targetMakefile;then
	echo -e "$CYAN Anchor : allredy modified $NC"
else
	string=$ANCHOR_BUILD_DIR
	if grep -qF "$string" $targetMakefile;then
		echo -e "$CYAN Anchor : $string Found $NC"
	else
		echo -e "$RED Anchor : $string Not found -> please check it $NC "
	fi
fi

string=$ANCHOR_CPP_PREFIX_CUST
if grep -qF "$string" $targetMakefile;then
	echo -e "$CYAN Anchor : $string Found $NC"
else
	echo -e "$RED Anchor : $string Not found -> please check it $NC "
fi

string=$ANCHOR_CPP_PREFIX_DEF
if grep -qF "$string" $targetMakefile;then
	echo -e "$CYAN Anchor : $string Found $NC"
else
	echo -e "$RED Anchor : $string Not found -> please check it $NC "
fi

string=$ANCHOR_C_OBJECTS
if grep -qF "$string" $targetMakefile;then
	echo -e "$CYAN Anchor : $string Found $NC"
else
	echo -e "$RED Anchor : $string Not found -> please check it $NC "
fi

string=$ANCHOR_C_COMPILE
if grep -qF "$string" $targetMakefile;then
	echo -e "$CYAN Anchor : $string Found $NC"
else
	echo -e "$RED Anchor : $string Not found -> please check it $NC "
fi

###############################################################
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

string=$BUILD_DIR_COMMENT
if grep -qF "$string" $targetMakefile;then
   echo "Found $string	-> Will not be replaced"
else
	echo "$string	-> Inserted"
	sed -i "/$ANCHOR_BUILD_DIR/i $BUILD_DIR_COMMENT" $targetMakefile
	sed -i "s/$ANCHOR_BUILD_DIR/$BUILD_DIR_NEW/g" $targetMakefile
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

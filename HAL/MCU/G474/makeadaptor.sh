#!/bin/bash

RED='\e[0;31m'
YELW='\e[0;33m'
BLUE='\e[0;34m'
PRPL='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'

NC='\e[0m'

textFile='Makefile'
dnv=$(grep -E -o -i "version.+\[[0-9].+d" $textFile)
version=$(echo $dnv | grep -E -o -i "version.+\[.*\]") 
date=$(grep -E -o -i "date.+\[.+" $textFile)
echo -e "${BLUE}" 
echo "Curretn Makefile Information"
echo " |-> $version"
echo " |-> $date"
echo -e "${NC}"

sed -i 's///g' Makefile

string='# CPP sources'
if grep -qF "$string" $textFile;then
   echo "Found $string so will not be replaced"
else
	echo "$string Is inserted"
	sed -i "/# C sources/i $string" "Makefile"
fi

string='CPP= $(GPP_PATH)/$(PREFIX)g++'
if grep -qF "$string" $textFile;then
   echo "Found $string so will not be replaced"
else
	echo "$string Is inserted"
	sed -i "/CC = \$(GCC_PATH)\/\$(PREFIX)gcc/a $string" $textFile
fi

#sed -i '/# CPP sources/a CPP_SOURCES = \ ' $textFile

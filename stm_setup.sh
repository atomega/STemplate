#!/bin/bash

packageManger="apt-get"

echo
echo "Welcome to STM32 Linux setup"
echo

read -p "do you want to continue (y/n) ?: " yesorno
if [ "$yesorno" = "y" ];
then
	sudo apt install -y gcc-arm-none-eabi
	sudo apt install -y stlink-tools
	sudo apt install -y gdb
	echo
	echo
	echo
	echo ">>> An smtcube/ directory will be created"
	mkdir stmcube
	echo ">>> you will be redirected to the download site of ST please download the ZIP file and place it on the stmcube/ directory"
	sensible-browser https://my.st.com/content/my_st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.license=1601130472038.product=STM32CubeMX.version=6.0.1.html
	

	echo
	echo
	read -p "Is the download complete and the zip file placed on stmcube/ directory (y/n) ?: " yesorno
	if [ "$yesorno" = "y" ]; then
		cd stmcube
		sudo unzip *.zip
		sudo chmod +x *.linux
		./*.linux
		cd ..
	fi
	echo

	sudo rm -r stmcube

	read -p "do you want to perform st-info --probe (y/n) ?: " yesorno
	if [ "$yesorno" = "y" ]; then
		st-info --probe
	fi
else 
    echo "aborted"
fi

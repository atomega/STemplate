include makefile.conf

#######################################
#Default make
#######################################
all:
	$(MAKE) --directory=$(MCU_MAKE_DIR)

#######################################
#Clean
#######################################
clean:
	$(MAKE) clean --directory=$(MCU_MAKE_DIR)

#######################################
#Burn to flash
#######################################
burn:
	st-flash write $(LOCAL_APPLICATION_DIR)/$(APPLICATION_NAME).bin 0x8000000

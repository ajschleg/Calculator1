#----------------------------------------------------------------------------
#       Make Workspace
#
# 
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /bin/mwc.pl -type make
#
#----------------------------------------------------------------------------


all: assignemt3

depend: assignemt3-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignemt3 $(@)

.PHONY: assignemt3
assignemt3:
	@$(MAKE) -f Makefile.assignemt3 all

.PHONY: assignemt3-depend
assignemt3-depend:
	@$(MAKE) -f Makefile.assignemt3 depend

project_name_list:
	@echo assignemt3

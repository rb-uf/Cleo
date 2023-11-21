TOPTARGETS := all clean

# Filter out power_libs/ from the list of subdirectories
SUBDIRS := $(filter-out power_libs/., $(wildcard */.))

# default:
# 	@echo $(SUBDIRS)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
		$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)
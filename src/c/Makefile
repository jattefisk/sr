SHELL=/bin/bash

SUBDIRS=file-io pointers threads cfgparse strings

include Makefile.def

all: TARGET := all
clean: TARGET := clean

all clean: $(SUBDIRS)

$(SUBDIRS):
    echo $(TARGET)
    @ $(MAKE) -C $@ $(TARGET)

.PHONY: $(SUBDIRS)


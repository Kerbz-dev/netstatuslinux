
include Config.mak

CC=g++
CC_C=gcc

BASE_CFLAGS=-pipe -m32

BROOT=linux
BR=$(BROOT)/Release
BD=$(BROOT)/Rebug

OBJR=$(SRC_FILES:%.cpp=$(BR)/%.o)
OBJD=$(SRC_FILES:%.cpp=$(BD)/%.o)

DEBUG_CFLAGS=$(BASE_CFLAGS) -g -pg 
RELEASE_CFLAGS=$(BASE_CFLAGS) -O2 -fPIC -fomit-frame-pointer -falign-loops=2 -falign-jumps=2 -falign-functions=2 -fno-strict-aliasing -fstrength-reduce

SHLIBCFLAGS=
#-fPIC
SHLIBLDFLAGS=-shared -m32

help:
	@echo This Makefile supports the following make rules:
	@echo Release - builds release version
	@echo Debug - builds debug version
	@echo clean - cleans all output files
	
Release:
	@echo ---
	@echo --- building \(release\)
	@echo ---
	$(MAKE) $(BR)/$(BINARY).so

	@echo ---
	@echo --- Release build complete.
	@echo ---
	@echo --- Binaries are in linux/release
	@echo ---
	@echo --- Please read readme.txt for installation instructions.
	@echo ---

Debug: $(BD)/$(BINARY).so

$(BR)/$(BINARY).so: $(BR) $(OBJR)
	$(CC) $(RELEASE_CFLAGS) $(SHLIBLDFLAGS) -o $@ $(OBJR)
  
$(BD)/$(BINARY).so: $(BD) $(OBJD)
	$(CC) $(DEBUG_CFLAGS) $(SHLIBLDFLAGS) -o $@ $(OBJD)

$(BR)/%.o: %.cpp $(HDR_FILES)
	$(CC) $(RELEASE_CFLAGS) $(SHLIBCFLAGS) -o $@ -c $<
  
$(BD)/%.o: %.cpp $(HDR_FILES)
	$(CC) $(DEBUG_CFLAGS) $(SHLIBCFLAGS) -o $@ -c $<


$(BR):
	@if [ ! -d $(BROOT) ];then mkdir $(BROOT);fi
	@if [ ! -d $(@) ];then mkdir $@;fi

$(BD):
	@if [ ! -d $(BROOT) ];then mkdir $(BROOT);fi
	@if [ ! -d $(@) ];then mkdir $@;fi
	
clean:
	@rm -rf $(BD) $(BR)
	
cleanRelease:
	@rm -rf $(BR)
	
cleanDebug:
	@rm -rf $(BR)

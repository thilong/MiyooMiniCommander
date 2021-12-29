CC = arm-linux-gnueabihf-gcc
CXX = arm-linux-gnueabihf-g++
STRIP = arm-linux-gnueabihf-strip

RESDIR:=res

CFLAGS = -I$(shell pwd)/../dependency/release/include/cust_inc/ -DDEVICE_MIYOO_MINI -marm -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -O3 -march=armv7ve -ffast-math -fomit-frame-pointer -fno-strength-reduce
CXXFLAGS = $(CFLAGS)

CXXFLAGS+= -O3 -fomit-frame-pointer -ffast-math -funroll-loops
CXXFLAGS+=-Wall -Wno-unknown-pragmas -Wno-format
CXXFLAGS+=-DRESDIR="\"$(RESDIR)\""

LDFLAGS = -L$(shell pwd)/../dependency/release/nvr/i2m/common/glibc/8.2.1/cust_libs/dynamic/ -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
LDFLAGS += -L$(shell pwd)/../dependency/release/nvr/i2m/common/glibc/8.2.1/mi_libs/dynamic/ -lmi_common -lmi_sys -lmi_disp -lmi_panel -lmi_gfx -lmi_divp -lmi_ao -lmad -lfreetype
LINKFLAGS = $(LDFLAGS)
#LINKFLAGS+=-s

ifdef V
	CMD:=
	SUM:=@\#
else
	CMD:=@
	SUM:=@echo
endif

OUTDIR:=output

EXECUTABLE:=$(OUTDIR)/DinguxCommander

OBJS:=main.o sdlutils.o resourceManager.o fileLister.o commander.o panel.o \
      dialog.o window.o fileutils.o viewer.o keyboard.o

DEPFILES:=$(patsubst %.o,$(OUTDIR)/%.d,$(OBJS))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(addprefix $(OUTDIR)/,$(OBJS))
	$(SUM) "  LINK    $@"
	$(CMD)$(CXX) $(LINKFLAGS) -o $@ $^

$(OUTDIR)/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(SUM) "  CXX     $@"
	$(CMD)$(CXX) $(CXXFLAGS) -MP -MMD -MF $(@:%.o=%.d) -c $< -o $@
	@touch $@ # Force .o file to be newer than .d file.

clean:
	$(SUM) "  RM      $(OUTDIR)"
	$(CMD)rm -rf $(OUTDIR)



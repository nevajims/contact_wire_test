###########################################################################
## Makefile generated for component 'fn_process_rail_data_DLL'. 
## 
## Makefile     : fn_process_rail_data_DLL_rtw.mk
## Generated on : Tue Mar 24 22:30:58 2026
## Final product: ./fn_process_rail_data_DLL.dll
## Product type : dynamic-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# DEF_FILE                Definition file

PRODUCT_NAME              = fn_process_rail_data_DLL
MAKEFILE                  = fn_process_rail_data_DLL_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2025a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2025a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/mepdw/Git/contact_wire_test
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = fn_process_rail_data_DLL_rtw_comp.rsp
CMD_FILE                  = fn_process_rail_data_DLL_rtw.rsp
DEF_FILE                  = $(PRODUCT_NAME).def
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    8.x
# ToolchainInfo Version:   2025a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./fn_process_rail_data_DLL.dll
PRODUCT_TYPE = "dynamic-library"
BUILD_TYPE = "Dynamic Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1 -DBUILDING_FN_PROCESS_RAIL_DATA_DLL
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=fn_process_rail_data_DLL

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_data.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rt_nonfinite.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rtGetNaN.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rtGetInf.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_initialize.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_terminate.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/find.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/nextpow2.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fft.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/minOrMax.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/linspace.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/abs.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/sum.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/interp1.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/pchip.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/bsearch.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/dot.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/pinv.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzsvdc.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzlangeM.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xnrm2.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xdotc.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/angle.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/mrdivide_helper.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/squeeze.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/ifft.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/mpower.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/flipud.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/exp.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xaxpy.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xrotg.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xrot.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xswap.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/round.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzlascl.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/div.cpp $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/FFTImplementationCallback.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = fn_process_rail_data_DLL_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj fn_process_rail_data_DLL_initialize.obj fn_process_rail_data_DLL_terminate.obj fn_process_rail_data_DLL.obj find.obj nextpow2.obj fft.obj minOrMax.obj linspace.obj abs.obj sum.obj interp1.obj pchip.obj bsearch.obj dot.obj pinv.obj xzsvdc.obj xzlangeM.obj xnrm2.obj xdotc.obj angle.obj mrdivide_helper.obj squeeze.obj ifft.obj mpower.obj flipud.obj exp.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj round.obj xzlascl.obj div.obj FFTImplementationCallback.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = -fvisibility=hidden
CFLAGS_OPTS = -fopenmp
CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_) $(CFLAGS_OPTS) $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = -fvisibility=hidden
CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_OPTS) $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#----------------------------------------
# Create a dynamic library
#----------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating dynamic library "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_SHAREDLIB_LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fn_process_rail_data_DLL_data.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fn_process_rail_data_DLL_initialize.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fn_process_rail_data_DLL_terminate.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fn_process_rail_data_DLL.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fn_process_rail_data_DLL.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nextpow2.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/nextpow2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fft.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/fft.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linspace.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/linspace.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abs.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/abs.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sum.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/sum.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


interp1.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/interp1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


pchip.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/pchip.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bsearch.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/bsearch.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


dot.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/dot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


pinv.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/pinv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzsvdc.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzsvdc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlangeM.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzlangeM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


angle.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/angle.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mrdivide_helper.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/mrdivide_helper.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ifft.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/ifft.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mpower.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/mpower.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


flipud.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/flipud.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


exp.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/exp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


round.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/round.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlascl.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/xzlascl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


div.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/div.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


FFTImplementationCallback.obj : $(START_DIR)/codegen/dll/fn_process_rail_data_DLL/FFTImplementationCallback.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."



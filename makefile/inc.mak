#
# common part of Makefile
# $Id: $
#
################################################################################

CC = `\
	if test "\`uname\`" = "AIX"; then echo xlc_r; \
	elif test "\`uname\`" = "HP-UX"; then echo cc; \
	elif test "\`uname\`" = "Linux"; then echo gcc; \
	else echo cc; \
	fi`

CFLAGS = $(MYDEFS) `\
	if test "\`uname\`" = "AIX"; then echo -D_IBMAIX \
		-g -qhalt=w -q64 -qpic=large -brtl \
		-D_BSD_SOURCE -Dinline=__inline__; \
	elif test "\`uname\`" = "HP-UX"; then echo -D_HPUX \
		-g +w2 +W 4276,2940,2111 +DD64 -Ae +z -mt \
		-D_BSD_SOURCE -D_XOPEN_SOURCE=600 \
		-D_XOPEN_SOURCE_EXTENDED \
		-D_HPUX_ALT_XOPEN_SOCKET_API; \
	elif test "\`uname\`" = "Linux"; then echo -D_LINUX\
		-g -Wall -Wextra -std=c99 -pedantic -fPIC -pthread \
		-D_GNU_SOURCE -D_H;\
	else echo \
		-g; \
	fi`

CXX = `\
	if test "\`uname\`" = "AIX"; then echo xlC_r; \
	elif test "\`uname\`" = "HP-UX"; then echo aCC; \
	elif test "\`uname\`" = "Linux"; then echo g++; \
	else echo g++; \
	fi`

CXXFLAGS = $(MYDEFS) `\
	if test "\`uname\`" = "AIX"; then echo -D_IBMAIX \
		-g -qhalt=w -q64 -qpic=large -brtl \
		-D_BSD_SOURCE; \
	elif test "\`uname\`" = "HP-UX"; then echo -D_HPUX \
		-g +w2 +W 4276,2940,2111 +DD64 -AA +z -mt \
		-D_BSD_SOURCE -D_XOPEN_SOURCE=600 \
		-D_XOPEN_SOURCE_EXTENDED \
		-D_HPUX_ALT_XOPEN_SOCKET_API; \
	elif test "\`uname\`" = "Linux"; then echo -D_LINUX\
		-g -O3 -Wall -Wno-long-long -pedantic -fPIC -pthread \
		-D_GNU_SOURCE -D_H ;\
	else echo \
		-g; \
	fi`

SHFLAGS = `\
	if test "\`uname\`" = "AIX"; then echo \
		-q64 -G; \
	elif test "\`uname\`" = "HP-UX"; then echo \
		+DD64 -b; \
	elif test "\`uname\`" = "Linux"; then echo \
		-shared; \
	else echo ""; \
	fi`

AR = `\
	if test "\`uname\`" = "AIX"; then echo ar -X 64 cru; \
	else echo ar cru; \
	fi`

RANLIB = ranlib

RM = rm -f

################################################################################
# include path and lib search path
CPPFLAGS = $(MYINCPATH) \
	-I$(PREFIX)/include \
	-I.

LDFLAGS = $(MYLIBS) \
	-L$(PREFIX)/lib \
	-L. \

################################################################################
# libs:
SYSLIBS = `\
	if test "\`uname\`" = "AIX"; then echo \
		-lm -lpthread; \
	elif test "\`uname\`" = "HP-UX"; then echo \
		-lm -lsec -lelf; \
	elif test "\`uname\`" = "Linux"; then echo \
		-ldl -lm -lcrypt -lpthread; \
	else echo ""; \
	fi`

LIBS = $(MYLIBS) $(SYSLIBS)


################################################################################
# compile rule for different kinds of src file
#
#
.SUFFIXES: .cc .ec .cpp .c

%.o : %.c
	@echo "Compiling $< ... \c"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "OK"

%.o : %.C
	@echo "Compiling $< ... \C"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "OK"

%.o : %.cc 
	@echo "Compiling $< ... \cc"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "OK"


%.o : %.cpp 
	@echo "Compiling $< ... \cpp"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "OK"

################################################################################
OBJ_c = $(SRC_c:.c=.o)
OBJ_C = $(SRC_C:.C=.o)
OBJ_cc = $(SRC_cc:.cc=.o)
OBJ_cpp = $(SRC_cpp:.cpp=.o)
OBJS = $(OBJ_c) $(OBJ_C) $(OBJ_cc) $(OBJ_cpp)
################################################################################
BINCOLOR="\033[37;1m"
MAKECOLOR="\033[32;1m"
ENDCOLOR="\033[0m"

clean:
	@find . -type f -name ?*.o? -exec rm -rf {} \;
	@find . -type f -perm /111 -exec rm -rf {} \;
	rm -f *.o;

echo:
	@echo "CC = $(CC)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "CXX = $(CXX)"
	@echo "CXXFLAGS = $(CXXFLAGS)"
	@echo "CPPFLAGS = $(CPPFLAGS)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "LIBS = $(LIBS)"
	@echo "AR = $(AR)"
	@echo "RANLIB = $(RANLIB)"
	@echo "SHFLAGS= $(SHFLAGS)"
	@echo "RM = $(RM)"
	@echo  $(SRC_cpp)
	@echo  $(SRC_c)

#   @echo $(OBJ_cpp)
#	@echo "$(wildcard *.o)"
#	@echo "mk=$(MAKE)"
################################################################################

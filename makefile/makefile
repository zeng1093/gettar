
all: hello
include inc.mak
MPDIR=$(HOME)/makefile
MYINCPATH = -I$(MPDIR)/src/freesoft
MYDEFS = -D_DEBUG=3 -DN_MSGG_TEST -DLUA_USE_POSIX -DLUA_USE_DLOPEN
MYLIBS = -L$(MPDIR)/lib -ldl #-llua -lbson -lcurses

MAKE = $(CXX) $(CXXFLAGS) $(CPPFLAGS)$(LIBS)

SRC_cpp=hello1.cpp\
		pr.cpp\
		test1.cpp
SRC_c =test2.c
 
hello:$(OBJS)
	$(MAKE) -o hello $(OBJS)

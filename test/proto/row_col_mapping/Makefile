# Makefile to build the SDL tests

srcdir  = .


CC      = g++
EXE	= 
CFLAGS  = -g -O2  -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR
INCLUDE = -I /home/larry/devel/force-brute -I /home/larry/devel/boost_1_55_0/boost -I /home/larry/devel/force-brute/test/proto/common

LIBS	=  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL_gfx -lSDL2_ttf -lfreetype -lboost_system -lboost_filesystem

TARGETS = rowcolmapping$(EXE) 

all: $(TARGETS) 


rowcolmapping$(EXE): $(srcdir)/main.cpp ../ConfigFileReader.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)


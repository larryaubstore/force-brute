# Makefile to build the SDL tests

srcdir  = .


CC      = g++
EXE	= 
CFLAGS  = -g -O2  -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR
INCLUDE = -I /home/larry/devel/force-brute 

LIBS	=  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL_gfx -lSDL2_ttf -lfreetype

TARGETS = blscreen$(EXE) 

all: $(TARGETS) 


blscreen$(EXE): $(srcdir)/projectionmap.cpp
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)


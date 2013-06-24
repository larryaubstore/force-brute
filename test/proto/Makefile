# Makefile to build the SDL tests

srcdir  = .

CC      = g++
EXE	= 
CFLAGS  = -g -O2 -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL
#CFLAGS  = -g -I/usr/include/SDL 
INCLUDE = -I /home/larry/devel/force-brute

LIBS	=  -L/usr/lib/i386-linux-gnu -lSDL -lSDL_image

TARGETS = zoom$(EXE) Timer.o

all: $(TARGETS)

Timer.o : ../../Timer.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

zoom$(EXE): $(srcdir)/zoom.cpp Timer.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)


clean:
	rm -f $(TARGETS)


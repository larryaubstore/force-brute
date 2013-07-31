# Makefile to build the SDL tests

srcdir  = .

saucelib = /home/larry/apps/sauce/.libs

CC      = g++
EXE	= 
CFLAGS  = -g -O2 -I/usr/include/SDL -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR
INCLUDE = -I /home/larry/devel/force-brute -I /home/larry/apps/sauce

LIBS	=  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL -lSDL_image -lSDL_gfx

TARGETS = tile$(EXE) Timer.o DynamicGrid.o Renderer.o Tile.o ConfigFileReader.o

all: $(TARGETS) 

#Tile.o : common/Tile.cpp
#	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

Timer.o : ../../Timer.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

DynamicGrid.o : common/DynamicGrid.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

ConfigFileReader.o : common/ConfigFileReader.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

Renderer.o : common/Renderer.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

Tile.o : common/Tile.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

zoom$(EXE): $(srcdir)/zoom.cpp Timer.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)




tile$(EXE): $(srcdir)/tile.cpp Timer.o Tile.o Renderer.o DynamicGrid.o ConfigFileReader.o $(saucelib)/libunittest.a common/DependencyInjection.h
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)


# Makefile to build the SDL tests

srcdir  = .

saucelib = /home/larry/apps/sauce/.libs

CC      = g++
EXE	= 
CFLAGS  = -g -O2  -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR
INCLUDE = -I /home/larry/devel/force-brute -I /home/larry/apps/sauce -I wallaroo/wallaroo  -I /home/larry/devel/boost_1_55_0/boost

LIBS	=  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL_gfx -lSDL2_ttf -lfreetype -lboost_system -lboost_filesystem  #libSDL2_ttf.so

TARGETS = tile$(EXE) Timer.o DynamicGrid.o Renderer.o Tile.o ConfigFileReader.o Injector.o show$(EXE)

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

Injector.o : common/Injector.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

zoom$(EXE): $(srcdir)/zoom.cpp Timer.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

show$(EXE): $(srcdir)/showimage.c Timer.o $(srcdir)/font.h
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

tile$(EXE): $(srcdir)/tile.cpp Timer.o Tile.o Renderer.o DynamicGrid.o ConfigFileReader.o Injector.o 
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)

# ./blender -b /home/larry/devel/proto1/montagne.blend -P /home/larry/devel/force-brute/test/proto/blender_scripts/RenderMapMontagne.py

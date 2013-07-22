# Makefile to build the SDL tests

srcdir  = .

CC      = g++
EXE	= 
CFLAGS  = -g -O2 -I/usr/include/SDL -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL
#CFLAGS  = -g -I/usr/include/SDL 
INCLUDE = -I /home/larry/devel/force-brute -I ../common 

LIBS	=  -lcpptest -lm # -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL -lSDL_image -lSDL_gfx

TARGETS = ProtoTestSuite$(EXE) TestDynamicGrid.o DynamicGrid.o Tile.o  #tile$(EXE) Timer.o

all: $(TARGETS)

#MockDynamicGrid.o : common/tests/MockDynamicGrid.h
#	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

Tile.o: ../common/Tile.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

DynamicGrid.o: ../common/DynamicGrid.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

TestDynamicGrid.o: TestDynamicGrid.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

ProtoTestSuite.o : ProtoTestSuite.cpp 
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

ProtoTestSuite$(EXE): $(srcdir)/ProtoTestSuite.cpp TestDynamicGrid.o DynamicGrid.o Tile.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)


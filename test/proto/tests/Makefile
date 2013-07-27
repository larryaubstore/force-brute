# Makefile to build the SDL tests

srcdir  = . 

CC      = g++
EXE	= 
CFLAGS  = -g -O2 -I/usr/include/SDL -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL
INCLUDE = -I /home/larry/devel/force-brute -I ../common 

LIBS	=  -lcpptest -lm 

TARGETS = ProtoTestSuite$(EXE) TestDynamicGrid.o Tile.o  

all: $(TARGETS)

#MockDynamicGrid.o : common/tests/MockDynamicGrid.h
#	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

Tile.o: ../common/Tile.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

TestDynamicGrid.o: TestDynamicGrid.cpp
	$(CC) $(INCLUDE) -c $?  -o $@ $(CFLAGS) $(LIBS)

ProtoTestSuite$(EXE): $(srcdir)/ProtoTestSuite.cpp TestDynamicGrid.o Tile.o ../common/DynamicGrid.h
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS) *.o


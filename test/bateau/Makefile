CC = g++

PROG = BATEAU
OBJS = bateau.o
TRGTS = COMMON | BLWORLD $(OBJS) runner TESTS testrunner

COMMONDIR = ../proto/common
TESTDIR = ../proto/tests

CFLAGS  = -g -O2  -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR

INCLUDE =  -I ../proto/wallaroo -I /home/larry/devel/boost_1_55_0/boost -I ../proto/common -I ../proto/blworld_to_screencoord  # -I /usr/local/include/SDL2
LIBS  =  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL_gfx -lSDL2_ttf -lfreetype -lboost_system -lboost_filesystem -L/usr/local/lib -lcpptest

$(PROG): $(TRGTS)

.c.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c $*.c $(LIBS)


runner: bateau.o $(COMMONDIR)/Timer.o $(COMMONDIR)/ConfigFileReader.o $(COMMONDIR)/FileReader.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

testrunner: $(TESTDIR)/ProtoTestSuite.o $(TESTDIR)/TestFileMapper.o $(TESTDIR)/TestBLWorldMapper.o  $(COMMONDIR)/FileMapper.o $(COMMONDIR)/BLWorldMapper.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

all: $(TRGTS)

COMMON:
	cd ../proto/common ; make COMMON

BLWORLD:
	cd ../proto/blworld_to_screencoord ; make BLWORLD

TESTS:
	cd ../proto/tests ; make TESTS 



clean:
	rm -f *.o *~
	cd ../proto/common ; make clean
	cd ../proto/blworld_to_screencoord ; make clean
	cd ../proto/tests ; make clean

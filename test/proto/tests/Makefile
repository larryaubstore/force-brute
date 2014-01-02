CC = g++




CFLAGS  = -g -O2  -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSAUCE_STD_TR1_SMART_PTR
PROG = TESTS
COMMONDIR = ../common
OBJS = TestFileMapper.o $(COMMONDIR)/FileReader.o $(COMMONDIR)/FileMapper.o $(COMMONDIR)/ConfigFileReader.o

INCLUDE =  -I ../wallaroo -I /home/larry/devel/boost_1_55_0/boost -I ../common 
LIBS  =  -L/usr/lib/i386-linux-gnu -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL_gfx -lSDL2_ttf -lfreetype -lboost_system -lboost_filesystem


$(PROG): $(OBJS)

.cpp.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c $*.cpp $(LIBS)


clean:
	rm -f *~ $(OBJS) $(PROG)

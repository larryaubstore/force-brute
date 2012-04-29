# LIBDIR=  -lSDL -lm  `sdl-config --libs`  -lSDL_image -lcpptest  -lstdc++ -lmockpp_cxxtest -L/home/larry/devel/mockpp-1.16.6/mockpp/.libs -lmockpp

# LIBDIR=  -lSDL -lm  `sdl-config --libs`  -lSDL_image -lcpptest   -lmockpp_cxxtest -L/home/larry/devel/mockpp-1.16.6/mockpp/.libs -lmockpp

LIBDIR=  -L/usr/local/lib -lSDL -lm  -lSDL_image

LIBDIRTEST=  -L/usr/local/lib -lSDL -lm  -lSDL_image -lcpptest   -lmockpp_cxxtest -lmockpp
# INCLUDEDIR = -I /home/larry/devel/mockpp-1.16.6/ -I /home/larry/devel/boost_1_47_0 -I . -I /usr/include/SDL/
# INCLUDEDIR = -I /home/larry/devel/mockpp-1.16.6/ -I . -I  /home/larry/devel/stl3_3

INCLUDEDIR = -I /usr/local/include/SDL/ -I . # -I /usr/include -I /usr/include/SDL
DEBUG= -g

OBJDIR = bin
DEPDIR = deps


TESTDIR = test
MOCKDIR = test/mock

all: EngineVideo TestSuite

EngineVideo : $(OBJDIR)/main.o $(OBJDIR)/Fetcher.o $(OBJDIR)/Timer.o $(OBJDIR)/GameModel.o $(OBJDIR)/GameModelController.o $(OBJDIR)/Loader.o $(OBJDIR)/Rule.o $(OBJDIR)/RuleFetcher.o $(OBJDIR)/PathMissile.o
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -o EngineVideo $(OBJDIR)/main.o $(OBJDIR)/Fetcher.o \
		$(OBJDIR)/Timer.o $(OBJDIR)/GameModel.o $(OBJDIR)/GameModelController.o $(OBJDIR)/Loader.o \
		$(OBJDIR)/Rule.o $(OBJDIR)/RuleFetcher.o \
		$(OBJDIR)/PathMissile.o

$(OBJDIR)/Timer.o : Timer.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c Timer.cpp -o $(OBJDIR)/Timer.o

$(OBJDIR)/main.o : main.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Fetcher.o : Fetcher.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c Fetcher.cpp -o $(OBJDIR)/Fetcher.o

$(OBJDIR)/GameModel.o : GameModel.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c GameModel.cpp -o $(OBJDIR)/GameModel.o

$(OBJDIR)/GameModelController.o : GameModelController.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c GameModelController.cpp -o $(OBJDIR)/GameModelController.o

$(OBJDIR)/Loader.o : Loader.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c Loader.cpp -o $(OBJDIR)/Loader.o

$(OBJDIR)/Rule.o : Rule.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c Rule.cpp -o $(OBJDIR)/Rule.o

$(OBJDIR)/RuleFetcher.o : RuleFetcher.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c RuleFetcher.cpp -o $(OBJDIR)/RuleFetcher.o

$(OBJDIR)/PathMissile.o : PathMissile.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c PathMissile.cpp -o $(OBJDIR)/PathMissile.o




TestSuite : $(OBJDIR)/ExampleTestSuite.o $(OBJDIR)/FetcherTest.o $(OBJDIR)/Fetcher.o $(OBJDIR)/GameModelControllerTest.o $(OBJDIR)/GameModelControllerMock.o $(OBJDIR)/GameModelMock.o $(OBJDIR)/FetcherMock.o $(OBJDIR)/LoaderTest.o $(OBJDIR)/Loader.o $(OBJDIR)/LoaderMock.o $(OBJDIR)/RuleFetcherTest.o $(OBJDIR)/RuleFetcherMock.o $(OBJDIR)/RuleFetcher.o $(OBJDIR)/Rule.o
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -o $(TESTDIR)/TestSuite \
		$(OBJDIR)/ExampleTestSuite.o \
		$(OBJDIR)/GameModelControllerTest.o \
		$(OBJDIR)/FetcherTest.o \
		$(OBJDIR)/Fetcher.o \
		$(OBJDIR)/GameModel.o \
		$(OBJDIR)/GameModelController.o \
		$(OBJDIR)/Timer.o \
		$(OBJDIR)/GameModelMock.o \
		$(OBJDIR)/GameModelControllerMock.o \
		$(OBJDIR)/FetcherMock.o \
		$(OBJDIR)/LoaderTest.o \
		$(OBJDIR)/Loader.o \
		$(OBJDIR)/LoaderMock.o \
		$(OBJDIR)/RuleFetcherTest.o \
		$(OBJDIR)/RuleFetcherMock.o \
		$(OBJDIR)/RuleFetcher.o \
		$(OBJDIR)/Rule.o \
		$(OBJDIR)/PathMissile.o

$(OBJDIR)/ExampleTestSuite.o : $(TESTDIR)/ExampleTestSuite.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(TESTDIR)/ExampleTestSuite.cpp -o $(OBJDIR)/ExampleTestSuite.o


$(OBJDIR)/FetcherTest.o : $(TESTDIR)/FetcherTest.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(TESTDIR)/FetcherTest.cpp -o $(OBJDIR)/FetcherTest.o

$(OBJDIR)/GameModelControllerTest.o : $(TESTDIR)/GameModelControllerTest.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(TESTDIR)/GameModelControllerTest.cpp -o $(OBJDIR)/GameModelControllerTest.o

$(OBJDIR)/LoaderTest.o: $(TESTDIR)/LoaderTest.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(TESTDIR)/LoaderTest.cpp -o $(OBJDIR)/LoaderTest.o		

$(OBJDIR)/RuleFetcherTest.o: $(TESTDIR)/RuleFetcherTest.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(TESTDIR)/RuleFetcherTest.cpp -o $(OBJDIR)/RuleFetcherTest.o

# MOCK OBJECTS
$(OBJDIR)/GameModelControllerMock.o: $(MOCKDIR)/GameModelControllerMock.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(MOCKDIR)/GameModelControllerMock.cpp -o $(OBJDIR)/GameModelControllerMock.o

$(OBJDIR)/GameModelMock.o: $(MOCKDIR)/GameModelMock.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(MOCKDIR)/GameModelMock.cpp -o $(OBJDIR)/GameModelMock.o

$(OBJDIR)/FetcherMock.o: $(MOCKDIR)/FetcherMock.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(MOCKDIR)/FetcherMock.cpp -o $(OBJDIR)/FetcherMock.o		

$(OBJDIR)/LoaderMock.o: $(MOCKDIR)/LoaderMock.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(MOCKDIR)/LoaderMock.cpp -o $(OBJDIR)/LoaderMock.o		

$(OBJDIR)/RuleFetcherMock.o: $(MOCKDIR)/RuleFetcherMock.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c $(MOCKDIR)/RuleFetcherMock.cpp -o $(OBJDIR)/RuleFetcherMock.o		

clean: 
	rm $(OBJDIR)/*.o




LIBDIR=  -lSDL -lm  -lSDL_image
LIBMOCKPP = /usr/local/lib
LIBDIRTEST=   $(LIBDIR) -lcpptest -lmockpp_cxxtest -lmockpp

INCLUDEDIR =  
INCLUDEDIRTEST = -I . -I scene/ 

DEBUG= -g

OBJDIR = bin
DEPDIR = deps


TESTDIR = test
MOCKDIR = test/mock

all: EngineVideo 

EngineVideo : $(OBJDIR)/main.o $(OBJDIR)/Fetcher.o $(OBJDIR)/Timer.o $(OBJDIR)/GameModel.o $(OBJDIR)/GameModelController.o $(OBJDIR)/Loader.o $(OBJDIR)/Rule.o $(OBJDIR)/RuleFetcher.o $(OBJDIR)/PathMissile.o $(OBJDIR)/Animation.o $(OBJDIR)/SceneStack.o
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -o EngineVideo $(OBJDIR)/main.o $(OBJDIR)/Fetcher.o \
		$(OBJDIR)/Timer.o $(OBJDIR)/GameModel.o $(OBJDIR)/GameModelController.o $(OBJDIR)/Loader.o \
		$(OBJDIR)/Rule.o $(OBJDIR)/RuleFetcher.o \
		$(OBJDIR)/PathMissile.o $(OBJDIR)/Animation.o $(OBJDIR)/SceneStack.o `sdl-config --libs --cflags` -lSDL_image

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

$(OBJDIR)/Animation.o : scene/Animation.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c scene/Animation.cpp -o $(OBJDIR)/Animation.o

$(OBJDIR)/SceneStack.o : scene/SceneStack.cpp
		g++ $(DEBUG) $(INCLUDEDIR) $(LIBDIR) -c scene/SceneStack.cpp -o $(OBJDIR)/SceneStack.o



TestSuite : EngineVideo $(OBJDIR)/ForceBruteTestSuite.o $(OBJDIR)/FetcherTest.o $(OBJDIR)/Fetcher.o $(OBJDIR)/GameModelControllerTest.o $(OBJDIR)/GameModelControllerMock.o $(OBJDIR)/GameModelMock.o $(OBJDIR)/FetcherMock.o $(OBJDIR)/LoaderTest.o $(OBJDIR)/Loader.o $(OBJDIR)/LoaderMock.o $(OBJDIR)/RuleFetcherTest.o $(OBJDIR)/RuleFetcherMock.o $(OBJDIR)/RuleFetcher.o $(OBJDIR)/Rule.o $(OBJDIR)/Animation.o $(OBJDIR)/AnimationTest.o $(OBJDIR)/SceneStackTest.o
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -o $(TESTDIR)/TestSuite \
		$(OBJDIR)/ForceBruteTestSuite.o \
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
		$(OBJDIR)/Animation.o \
		$(OBJDIR)/AnimationTest.o \
		$(OBJDIR)/PathMissile.o \
	  $(OBJDIR)/SceneStack.o \
		$(OBJDIR)/SceneStackTest.o `sdl-config --libs --cflags` -lSDL_image $(LIBDIRTEST)

$(OBJDIR)/ForceBruteTestSuite.o : $(TESTDIR)/ForceBruteTestSuite.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/ForceBruteTestSuite.cpp -o $(OBJDIR)/ForceBruteTestSuite.o

$(OBJDIR)/FetcherTest.o : $(TESTDIR)/FetcherTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/FetcherTest.cpp -o $(OBJDIR)/FetcherTest.o

$(OBJDIR)/GameModelControllerTest.o : $(TESTDIR)/GameModelControllerTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/GameModelControllerTest.cpp -o $(OBJDIR)/GameModelControllerTest.o

$(OBJDIR)/LoaderTest.o: $(TESTDIR)/LoaderTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/LoaderTest.cpp -o $(OBJDIR)/LoaderTest.o		

$(OBJDIR)/RuleFetcherTest.o: $(TESTDIR)/RuleFetcherTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/RuleFetcherTest.cpp -o $(OBJDIR)/RuleFetcherTest.o

# MOCK OBJECTS
$(OBJDIR)/GameModelControllerMock.o: $(MOCKDIR)/GameModelControllerMock.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(MOCKDIR)/GameModelControllerMock.cpp -o $(OBJDIR)/GameModelControllerMock.o

$(OBJDIR)/GameModelMock.o: $(MOCKDIR)/GameModelMock.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(MOCKDIR)/GameModelMock.cpp -o $(OBJDIR)/GameModelMock.o

$(OBJDIR)/FetcherMock.o: $(MOCKDIR)/FetcherMock.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(MOCKDIR)/FetcherMock.cpp -o $(OBJDIR)/FetcherMock.o		

$(OBJDIR)/LoaderMock.o: $(MOCKDIR)/LoaderMock.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(MOCKDIR)/LoaderMock.cpp -o $(OBJDIR)/LoaderMock.o		

$(OBJDIR)/RuleFetcherMock.o: $(MOCKDIR)/RuleFetcherMock.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(MOCKDIR)/RuleFetcherMock.cpp -o $(OBJDIR)/RuleFetcherMock.o		

$(OBJDIR)/AnimationTest.o : $(TESTDIR)/scene/AnimationTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/scene/AnimationTest.cpp -o $(OBJDIR)/AnimationTest.o

$(OBJDIR)/SceneStackTest.o : $(TESTDIR)/scene/SceneStackTest.cpp
		g++ $(DEBUG) $(INCLUDEDIRTEST) $(LIBDIRTEST) -c $(TESTDIR)/scene/SceneStackTest.cpp -o $(OBJDIR)/SceneStackTest.o


clean: 
	rm $(OBJDIR)/*.o
	rm EngineVideo
	rm $(TESTDIR)/TestSuite




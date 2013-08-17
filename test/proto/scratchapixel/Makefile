
srcdir  = .

CC      = g++

TARGETS = testGL perspective.o

all: $(TARGETS)

perspective.o : $(srcdir)/projectionmatrices.cpp
	$(CC) $(INCLUDE) -c $? -o $@  $(CFLAGS) $(LIBS)


testGL: perspective.o
	$(CC) $(INCLUDE) -o $@ $? $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)

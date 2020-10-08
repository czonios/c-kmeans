IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

TMPDIR=.tmp
GDIR=../graphs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = util.h k-means.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = util.o main.o k-means.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -fopenmp -Wall -Wextra -Wpedantic -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -fopenmp -Wall -Wextra -Wpedantic -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(TMPDIR) \ 
	rm -rf $(GDIR) \
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ debug

debug: $(OBJ)
	$(CC) -fopenmp -Wall -Wextra -Wpedantic -o $@ $^ $(CFLAGS) $(LIBS) -g

$(info $(shell mkdir -p $(ODIR)))
$(info $(shell mkdir -p $(TMPDIR)))
$(info $(shell mkdir -p $(GDIR)))
CC = gcc
FILES = factorial_3.c function3.c
OUT_EXE = program.o
CFLAGS=-I.
DEPS = function3.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)
clean:
	rm -f *.o core
	rm -f *.out core
rebuild: clean build

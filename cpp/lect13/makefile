MAIN_OBJS = inheritance.cpp
CC = g++

MAIN = a.out

$(MAIN): $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

clean: 

	rm -f *.o $(MAIN)
	rm -f *.out $(MAIN)
debug:
	$(CC)  $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS) -g

build:
	 $(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

run:
	./a.out
clear:
	clear        

ccbr: clear clean build run 
cbr: clean build run 

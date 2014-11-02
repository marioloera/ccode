MAIN_OBJS = solvePlanningProblem.cc AStarNode.cc Position.cc PRM.cc PRMNode.cc SingleCircleWorld.cc World.cc
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
clear-run:
	clear
	./a.out

cbr: clean build run 
ccbr: clear clean build run 
cbcr: clean build clear-run 

MAIN_OBJS = solvePlanningProblem.cc AStarNode.cc Position.cc PRM.cc PRMNode.cc SingleCircleWorld.cc MyWorld.cc  World.cc Obstacle.cc Rectangle.cc Circle.cc
CC = g++
MAIN = a.out

$(MAIN): $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

debug:
	$(CC)  $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS) -g
build:
	 $(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)
clean: 
	rm -f *.o $(MAIN)
	rm -f *.out $(MAIN)
	rm -f *.m $(MAIN)
clear:
	clear
run:
	./a.out
run0:
	./a.out -p"problem0.txt"
run1:
	./a.out -p"problem1.txt"
run2:
	./a.out -p"problem2.txt"
run3:
	./a.out -p"problem3.txt"
run4:
	./a.out -p"problem4.txt"
cb: clean build 
ccbr: clear clean build run 
ccbr0: clear clean build run0 
ccbr1: clear clean build run1 
ccbr2: clear clean build run2 
ccbr3: clear clean build run3 
ccbr4: clear clean build run4 

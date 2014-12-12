MAIN_OBJS = solvePlanningProblem.cc AStarNode.cc Position.cc PRM.cc PRMNode.cc SingleCircleWorld.cc MyWorld.cc World.cc Obstacle.cc Rectangle.cc Circle.cc
CC = g++
MAIN = a.out

$(MAIN): $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

debug:
	$(CC)  $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS) -g
build:
	 $(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)
clean: 
	rm -f *.o
	rm -f *.out
	rm -f *.m
r:
	./a.out -w "MyWorld" -p "problem1.txt"

run:
	rm -f *.m
	./a.out
run0:
	rm -f *.m
	./a.out -p"problem0.txt"
run1:
	rm -f *.m
	./a.out -p"problem1.txt"
run2:
	rm -f *.m
	./a.out -p"problem2.txt"
run3:
	rm -f *.m 
	./a.out -p"problem3.txt"
run4:
	rm -f *.m 
	./a.out -p"problem4.txt"
run5:
	rm -f *.m
	./a.out -p"problem5.txt"
run6:
	rm -f *.m 
	./a.out -p"problem6.txt"
run7:
	rm -f *.m 
	./a.out -p"problem7.txt"
cb: clean build 


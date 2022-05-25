
projectx: project.o lists.o
	g++ -Wall -Wextra project.o lists.o -o projectx

project.o: project.cpp project.h lists.h
	g++ -Wall -Wextra -c project.cpp

lists.o: lists.cpp lists.h
	g++ -Wall -Wextra -c lists.cpp

clean:
	rm -f project.o lists.o projectx


a2q2: a2q2.o maze.o
	g++ -std=c++14 a2q2.o maze.o -o a2q2

maze.o: maze.cc maze.h
	g++ -std=c++14 -c maze.cc

a2q2.o: a2q2.cc maze.h
	g++ -std=c++14 -c a2q2.cc

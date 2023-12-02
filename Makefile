all: game

game: game.o maze.o
	g++ -o game game.o maze.o

game.o: game.cpp maze.h
	g++ -c game.cpp

maze.o: maze.cpp maze.h
	g++ -c maze.cpp

game: ./game

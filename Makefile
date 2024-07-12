COMPILER=g++
FLAGS=-lm -lraylib -Wall -Wextra

game.out: main.cpp src/*.cpp
	$(COMPILER) main.cpp ./src/*.cpp -o game.out $(FLAGS)
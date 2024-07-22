COMPILER=g++
FLAGS=-lm -lraylib -Wall -Wextra -fsanitize=address -g

game.out: main.cpp src/*.cpp
	$(COMPILER) main.cpp ./src/*.cpp -o game.out $(FLAGS)
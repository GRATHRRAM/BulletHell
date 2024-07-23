COMPILER=g++
FLAGS=-Wall -Wextra

COMPILER_WIN=x86_64-w64-mingw32-g++
RAYLIB_LIB_WIN=./win/lib
RAYLIB_HEADERS_WIN=./win/inc
WIN_LIBS=-static -lm -lraylib -lopengl32 -lgdi32 -lwinmm -lgcc -lstdc++ -lwinpthread

debug: FLAGS += -fsanitize=address -g

game.out: main.cpp src/*.cpp
	$(COMPILER) main.cpp ./src/*.cpp -o game.out -lm -lraylib -lGL -lpthread -ldl -lrt -lX11 $(FLAGS)

win: game.exe

game.exe: main.cpp src/*.cpp
	$(COMPILER_WIN) main.cpp ./src/*.cpp -o game.exe $(WIN_LIBS) -I$(RAYLIB_HEADERS_WIN) -L$(RAYLIB_LIB_WIN) $(FLAGS)
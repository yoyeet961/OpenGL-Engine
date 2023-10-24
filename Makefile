CFLAGS = -std=c++17
LDFLAGS = -lopengl32 -lgdi32

SRC = *.c *.cpp # main.cpp glad.c game.cpp
OBJ = $(SRC:.cpp=build/o/.o)

all: build/build.exe

build.exe: *.cpp *.hpp
	@echo -e "\033[34;34mCompiling \033[32;32m$< \033[0m"
	@g++ $(CFLAGS) -o build/build.exe $(SRC) $(LDFLAGS)

.PHONY: test clean

test: build.exe
	./build/build.exe

clean:
	rm -f $(OBJ) build/build.exe
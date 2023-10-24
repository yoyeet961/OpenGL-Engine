CFLAGS = -std=c++17

build.exe: *.cpp *.hpp
	@echo -e "\033[34;34mCompiling \033[32;32m$< \033[0m"
	@g++ $(CFLAGS) -o build/build.exe *.cpp

.PHONY: test clean

test: build.exe
	./build/build.exe

clean:
	rm -f build
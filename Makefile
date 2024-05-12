# Makefile -- socket-on-second

BIN=./build/socket-on-second.exe

all: ${BIN}

${BIN}: build src/*.cpp src/*.c src/*.h
	clang -o ${BIN} --pedantic src/*.cpp src/*.c

src/*.cpp src/*.c src/*.h:


build:
	mkdir -p build

clean:
	rm -r ./build/*

run: all
	${BIN}

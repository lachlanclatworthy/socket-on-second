# Makefile -- socket-on-second

GXX_OPTS=--std=gnu++17 --pedantic
BIN=./build/socket-on-second.exe

all: ${BIN}

${BIN}: build src/*.cpp src/*.c src/*.h
	g++ ${GXX_OPTS} -o ${BIN} src/*.cpp src/*.c

src/*.cpp src/*.c src/*.h:


build:
	mkdir -p build

clean:
	rm -r ./build/*

run: all
	${BIN}

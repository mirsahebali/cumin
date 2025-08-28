.PHONY: all configure clean install build run

run: build start

all: install configure build start

configure:
	cd build && cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug

install:
	conan install . --output-folder=build  --build=missing --settings=build_type=Debug

build:
	cmake --build build

start:
	./build/cumin

clean:
	rm -rf build


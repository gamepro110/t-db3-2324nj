.PHONY: all clean

all: compile

configure:
	mkdir build &&\
	cd build &&\
	cmake .. &&\
	:

compile:
	cd build &&\
	cmake --build . &&\
	:

clean:
	@rm -r build

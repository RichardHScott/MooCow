CC=gcc
CCX=g++

CFLAGS=-std=gnu99 -Wall -Wextra -g
CCXFLAGS=-g -std=c++11

c_source_files := $(wildcard *.cpp)
c_object_files := $(patsubst %.cpp, %.o, $(c_source_files))
out_file := moocow

all: main 

main: $(c_object_files)
	$(CCX) -o $(out_file) $(c_object_files) $(CCXFLAGS)

%.o: %.cpp
	$(CCX) -c $< -o $@ $(CCXFLAGS)

clean:
	@rm -r *.o

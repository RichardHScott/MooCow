CC=gcc
CCX=g++

CCFLAGS=-std=gnu99 -Wall -Wextra -g
CCXFLAGS=-g -std=c++11

INCLUDES=./

c_source_files := $(wildcard *.c)
c_object_files := $(patsubst %.c, %.o, $(c_source_files))
out_file := moocow

all: main 

main: $(c_object_files)
	$(CC) -o $(out_file) $(c_object_files) $(CCFLAGS) -I$(INCLUDES)

%.o: %.c
	$(CC) -c $< -o $@ $(CCFLAGS) -I$(INCLUDES)

clean:
	@rm -r *.o moocow

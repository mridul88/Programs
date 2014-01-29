#Enable g++ complier
CC = gcc
CXX = g++
# Set Wall 
CPPFLAGS=-Wall -g -pedantic -I$(GTEST_DIR)/include
LDLIBS=-lpthread
#G_test path
GTEST_DIR=/home/mridul/gtest

all: test main

main: linked_list.o linked_list_main.o
	$(CXX) $(CPPFLAGS) linked_list_main.o linked_list.o -o linked_list_main.out 
 
test: linked_list_test.o linked_list.o $(LDLIBS) $(GTEST_DIR)/build/libgtest.a $(GTEST_DIR)/build/libgtest_main.a 
	$(CXX) $(CPPFLAGS) linked_list.o linked_list_test.o $(GTEST_DIR)/build/libgtest.a $(GTEST_DIR)/build/libgtest_main.a $(LDLIBS) -o linked_list_test.out

check: test
	./linked_list_test.out

run: all
	./linked_list_main.out
	
clean:
	rm -rf *.o *.out

.PHONY: main test all clean check run

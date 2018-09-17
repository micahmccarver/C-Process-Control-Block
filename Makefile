# Makefile
# Micah McCarver and Brandon Holman 
# CS433 - Assignment 1 - Priority Queue of Processes
# Description: Makefile can be run by using the make command  
# Due: 9/18/2017

executable: main.o PCB.o
	g++ main.o PCB.o -o executable

main.o: main.cpp
	g++ -c main.cpp

PCB.o: PCB.cpp PCB.h
	g++ -c PCB.cpp

clean:
	rm -rf *o executable 

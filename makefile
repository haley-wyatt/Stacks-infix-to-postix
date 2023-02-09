#Name: Wyatt Haley
#Class: CS 302 w/ Erin Keith
#Date: 10/01/2022
#Programming Assignment 3
#File name: makefile

all: executable

executable: driver.o
	g++ driver.o -o executable 

driver.o: linkedstack.h
	g++ -c driver.cpp

clean:
	rm *.o executable
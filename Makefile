#Makefile created 10/29/2016

#FLAGS
CFLAGS = -std=c++11 -g -Wall
CC = g++

#build target executable from all program files in directory
Project: Main.cpp List.cpp
	$(CC) -o Project Main.cpp List.cpp $(CFLAGS) -I/.

clean:
	rm Project

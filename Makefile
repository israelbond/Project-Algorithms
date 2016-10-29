
#Makefile for Skip List Project

#set up flags
CFLAGS = -std=c++11 -g -Wall
CC = g++

#build target executable which accounts for all program files in the direct
SkipList: main.cpp list.cpp 
        $(CC) -o main.cpp list.cpp 
clean:
    rm SkipList

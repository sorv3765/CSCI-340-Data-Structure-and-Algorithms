#
# PROGRAM:    Assignment 4
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   02-28-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4: assignment4.o
	g++ $(CCFLAGS) -o assignment4.exe assignment4.o

# Rules to compile source code files to object code
assignment4.o: assignment4.cc assignment4.h
	g++ $(CCFLAGS) -c assignment4.cc

#Run with the input file
run:
	./assignment4.exe<assignment4input.txt
	
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment4 assignment4.exe

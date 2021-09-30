#
# PROGRAM:    Assignment 2
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   02-09-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment2: assignment2.o
	g++ $(CCFLAGS) -o assignment2 assignment2.o

# Rules to compile source code files to object code
assignment2.o: assignment2.cc
	g++ $(CCFLAGS) -c assignment2.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment2

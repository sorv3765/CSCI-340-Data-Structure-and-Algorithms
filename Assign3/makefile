#
# PROGRAM:    Assignment 3
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   02-17-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment3: assignment3.o
	g++ $(CCFLAGS) -o assignment3 assignment3.o

# Rules to compile source code files to object code
assignment3.o: assignment3.cc
	g++ $(CCFLAGS) -c assignment3.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment3

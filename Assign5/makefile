
#
# PROGRAM:    Assignment 5
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   03-10-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment5: assignment5.o
	g++ $(CCFLAGS) -o assignment5 assignment5.o

# Rules to compile source code files to object code
assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment5

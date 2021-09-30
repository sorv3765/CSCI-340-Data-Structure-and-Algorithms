#
# PROGRAM:    lab1
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   01-31-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment1: assignment1.o
	g++ $(CCFLAGS) -o assignment1 assignment1.o

# Rules to compile source code files to object code
assignment1.o: assignment1.cc
	g++ $(CCFLAGS) -c assignment1.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment1

#
# PROGRAM:    lab1
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   01-26-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
lab1: lab1.o
	g++ $(CCFLAGS) -o lab1 lab1.o

# Rules to compile source code files to object code
lab1.o: lab1.cpp
	g++ $(CCFLAGS) -c lab1.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o lab1

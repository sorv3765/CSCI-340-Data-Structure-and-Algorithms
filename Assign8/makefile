#
# PROGRAM:    assignment8
# PROGRAMMER: Shaniel O. Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:  04-19-2016
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment8: assignment8.o
	g++ $(CCFLAGS) -o assignment8 assignment8.o

# Rules to compile source code files to object code
assignment8.o: assignment8.cc assignment8.h
	g++ $(CCFLAGS) -c assignment8.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment8

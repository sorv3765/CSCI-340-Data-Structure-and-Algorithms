#
# PROGRAM:    assignment9
# PROGRAMMER: Shaniel O. Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:  04-27-2016
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment9: assignment9.o
	g++ $(CCFLAGS) -o assignment9 assignment9.o

# Rules to compile source code files to object code
assignment9.o: assignment9.cc assignment9.h
	g++ $(CCFLAGS) -c assignment9.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment9


#
# PROGRAM:    Assignment 6
# PROGRAMMER: Shaniel O Rivas Verdejo
# LOGON ID:   z1123907
# DATE DUE:   03-30-17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
#assignment6: assignment6.o assignment5.o assignment6main.o
#	g++ $(CCFLAGS) -o assignment6 assignment6.o assignment5.o assignment6main.o

# Rules to compile source code files to object code
#assignment6.o: assignment5.cc assignment5.h assignment6main.cc assignment6.cc assignment6.h 
#	g++ $(CCFLAGS) -c assignment6.cc

# Rules to compile source code files to object code
#assignment5.o: assignment5.cc assignment5.h
#	g++ $(CCFLAGS) -c assignment5.cc

# Rules to compile source code files to object code
#assignment6main.o: assignment6main.cc assignment6.h assignment6.cc
#	g++ $(CCFLAGS) -c assignment6main.cc

#Compile the code to executable form
assignment6.exe:assignment5.cc assignment6.cc assignment6main.cc
	g++ $(CCFLAGS) assignment5.cc assignment6.cc assignment6main.cc -o assignment6.exe


# Pseudo-target to remove object code and executable files
clean:
	-rm assignment6.exe



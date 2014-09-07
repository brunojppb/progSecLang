#
# Source: http://cs.millersville.edu/~katz/linuxHelp/Makefile.txt
#
# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

Objects =  fan_fork.o fork_example2.o fork_exec.o fork_test.o fork_worker.o process_id.o simple_fork.o chain_fork.o tree_fork.o

# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

proj1 = sum_two_numbers.o
proj2 = sales_prediction.o
proj3 = sales_tax.o


#------------ no need to change between these lines -------------------
CFLAGS = -g -Wall
.SUFFIXES: .cxx .cpp .c

.cxx.o:
	g++ $(CFLAGS) -c $<

.cpp.o:
	g++ $(CFLAGS) -c $<

.c.o:
	g++ $(CFLAGS) -c $<


#------------ no need to change between these lines -------------------


#------------ targets --------------------------------------------
# describe how to create the targets - often there will be only one target

all: sum_two_numbers sales_prediction sales_tax

sum_two_numbers: $(proj1)
	g++ $(CFLAGS) $(proj1) -o sum_two_numbers

sales_prediction: $(proj2)
	g++ $(CFLAGS) $(proj2) -o sales_prediction

sales_tax: $(proj3)
	g++ $(CFLAGS) $(proj3) -o sales_tax


clean:
	rm -f $(proj1) $(proj2) $(proj3) $(proj4) $(proj5) $(proj6) $(proj7) $(proj8) $(proj9) sum_two_numbers sales_prediction sales_tax

#------------ dependencies --------------------------------------------
# put the .o that depends on a .h, then colon, then TAB, then the .h

#class1.o:	class1.h
#class2.o:	class2.h
#theProject.o:	class1.h class2.h



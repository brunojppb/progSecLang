#
# Source: http://cs.millersville.edu/~katz/linuxHelp/Makefile.txt
#
# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

Objects =  question9.o question10.o question11.o question12.o question13.o question14.o question15.o question16.o

# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

quest9 = question9.o
quest10 = question10.o
quest11 = question11.o
quest12 = question12.o
quest13 = question13.o
quest14 = question14.o
quest15 = question15.o
quest16 = question16.o


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

all: question_9 question_10 question_11 question_12 question_13 question_14 question_15 question_16

question_9: $(quest9)
	g++ $(CFLAGS) $(quest9) -o question_9

question_10: $(quest10)
	g++ $(CFLAGS) $(quest10) -o question_10

question_11: $(quest11)
	g++ $(CFLAGS) $(quest11) -o question_11

question_12: $(quest12)
	g++ $(CFLAGS) $(quest12) -o question_12

question_13: $(quest13)
	g++ $(CFLAGS) $(quest13) -o question_13

question_14: $(quest14)
	g++ $(CFLAGS) $(quest14) -o question_14

question_15: $(quest15)
	g++ $(CFLAGS) $(quest15) -o question_15

question_16: $(quest16)
	g++ $(CFLAGS) $(quest16) -o question_16


clean:
	rm -f $(quest9) $(quest10) $(quest11) $(quest12) $(quest13) $(quest14) $(quest15) $(quest16)

#------------ dependencies --------------------------------------------
# put the .o that depends on a .h, then colon, then TAB, then the .h

#class1.o:	class1.h
#class2.o:	class2.h
#theProject.o:	class1.h class2.h

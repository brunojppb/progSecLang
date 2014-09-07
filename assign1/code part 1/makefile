#
# Source: http://cs.millersville.edu/~katz/linuxHelp/Makefile.txt
#
# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

Objects =  question1.o question2.o question3.o question4.o question5.o question6.o question7.o question8.o

# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

quest1 = question1.o
quest2 = question2.o
quest3 = question3.o
quest4 = question4.o
quest5 = question5.o
quest6 = question6.o
quest7 = question7.o
quest8 = question8.o


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

all: question_1 question_2 question_3 question_4 question_5 question_6 question_7 question_8

question_1: $(quest1)
	g++ $(CFLAGS) $(quest1) -o question_1

question_2: $(quest2)
	g++ $(CFLAGS) $(quest2) -o question_2

question_3: $(quest3)
	g++ $(CFLAGS) $(quest3) -o question_3

question_4: $(quest4)
	g++ $(CFLAGS) $(quest4) -o question_4

question_5: $(quest5)
	g++ $(CFLAGS) $(quest5) -o question_5

question_6: $(quest6)
	g++ $(CFLAGS) $(quest6) -o question_6

question_7: $(quest7)
	g++ $(CFLAGS) $(quest7) -o question_7

question_8: $(quest8)
	g++ $(CFLAGS) $(quest8) -o question_8


clean:
	rm -f $(quest1) $(quest2) $(quest3) $(quest4) $(quest5) $(quest6) $(quest7) $(quest8)

#------------ dependencies --------------------------------------------
# put the .o that depends on a .h, then colon, then TAB, then the .h

#class1.o:	class1.h
#class2.o:	class2.h
#theProject.o:	class1.h class2.h



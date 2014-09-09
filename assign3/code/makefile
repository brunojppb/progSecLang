#
# Source: http://cs.millersville.edu/~katz/linuxHelp/Makefile.txt
#
# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

Objects =  question01.o question02.o question03.o question04.o question05.o question06.o question07.o question08.o question09.o question10.o question11.o question12.o question13.o

# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

quest1 = question01.o
quest2 = question02.o
quest3 = question03.o
quest4 = question04.o
quest5 = question05.o
quest6 = question06.o
quest7 = question07.o
quest8 = question08.o
quest9 = question09.o
quest10 = question10.o
quest11 = question11.o
quest12 = question12.o
quest13 = question13.o


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

all: question_01 question_02 question_03 question_04 question_05 question_06 question_07 question_08 question_09 question_10 question_11 question_12 question_13

question_01: $(quest1)
	g++ $(CFLAGS) $(quest1) -o question_01

question_02: $(quest2)
	g++ $(CFLAGS) $(quest2) -o question_02

question_03: $(quest3)
	g++ $(CFLAGS) $(quest3) -o question_03

question_04: $(quest4)
	g++ $(CFLAGS) $(quest4) -o question_04

question_05: $(quest5)
	g++ $(CFLAGS) $(quest5) -o question_05

question_06: $(quest6)
	g++ $(CFLAGS) $(quest6) -o question_06

question_07: $(quest7)
	g++ $(CFLAGS) $(quest7) -o question_07

question_08: $(quest8)
	g++ $(CFLAGS) $(quest8) -o question_08

question_09: $(quest9)
	g++ $(CFLAGS) $(quest9) -o question_09

question_10: $(quest10)
	g++ $(CFLAGS) $(quest10) -o question_10

question_11: $(quest11)
	g++ $(CFLAGS) $(quest11) -o question_11

question_12: $(quest12)
	g++ $(CFLAGS) $(quest12) -o question_12

question_13: $(quest13)
	g++ $(CFLAGS) $(quest13) -o question_13

clean:
	rm -f $(quest1) $(quest2) $(quest3) $(quest4) $(quest5) $(quest6) $(quest7) $(quest8) $(quest9) $(quest10) $(quest11) $(quest12) $(quest13)

#------------ dependencies --------------------------------------------
# put the .o that depends on a .h, then colon, then TAB, then the .h

#class1.o:	class1.h
#class2.o:	class2.h
#theProject.o:	class1.h class2.h

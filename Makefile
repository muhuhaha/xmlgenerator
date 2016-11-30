##########################################
# variables
##########################################
CC			= g++
CPPFLAGS	= -I/usr/include/libxml2
LFLAGS		= -lxml2

##########################################
# source codes 
##########################################


##########################################
# compile/link
##########################################
all: xmlTest 

xmlTest: xmltest.o
	@echo --------------------------------------------
	@echo -- option : xmlTest
	@echo compile/build : xmltest.cpp
	@echo --------------------------------------------
	
	$(CC) -o xmlTest $(CPPFLAGS) xmltest.cpp $(LFLAGS)

clean:
	@echo --------------------------------------------
	@echo -- option : clean 
	@echo clean all objects and executable 
	@echo --------------------------------------------
	
	rm -f *.o xmlTest


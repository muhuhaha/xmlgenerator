##########################################
# variables
##########################################
CC			= g++
CPPFLAGS	= -I/usr/include/libxml2
LFLAGS		= -lxml2

##########################################
# source codes 
##########################################

SOURCE		= xmlGenerator.cpp
OUTPUT		= xmlGenerator

##########################################
# compile/link
##########################################
all: xmlGenerator 

xmlGenerator: xmlGenerator.o
	@echo --------------------------------------------
	@echo -- option : xmlGenerator
	@echo compile/build : xmlGenerator.cpp
	@echo --------------------------------------------
	
	$(CC) -o $(OUTPUT) -g $(CPPFLAGS) $(SOURCE) $(LFLAGS)

clean:
	@echo --------------------------------------------
	@echo -- option : clean 
	@echo clean all objects and executable 
	@echo --------------------------------------------
	
	rm -f *.o $(OUTPUT) 

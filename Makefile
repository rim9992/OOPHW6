# Homework 5
# Robbie Robot Shop
# Michael Currie 
# Anna Cox 
# Rabab Antria 
# Ricardo Morales

CXXFLAGS = -std=c++11

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable

executable: main.o
	$(CXX) $(CXXFLAGS) main.o
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -w -c main.cpp
	
clean:
	rm -f *.o *.out

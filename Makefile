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

executable: main.o RobotPart.o Locomotor.o Battery.o
	$(CXX) $(CXXFLAGS) main.o RobotPart.o Locomotor.o Battery.o
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -w -c main.cpp
RobotPart.o: RobotPart.cpp
	$(CXX) $(CXXFLAGS) -w -c RobotPart.cpp
Locomotor.o: Locomotor.cpp
	$(CXX) $(CXXFLAGS) -w -c Locomotor.cpp
Battery.o: Battery.cpp
	$(CXX) $(CXXFLAGS) -w -c Battery.cpp
	
clean:
	rm -f *.o *.out


# Tests
testAll: testRobotPart testLocomotor
	./testRobotPart.out
	./testLocomotor.out

testRobotPart: RobotPart.o Locomotor.o
	$(CXX) $(CXXFLAGS) -w -c RobotPartTest.cpp
	$(CXX) $(CXXFLAGS) -o testRobotPart.out RobotPart.o Locomotor.o RobotPartTest.o
testLocomotor: Locomotor.o RobotPart.o
	$(CXX) $(CXXFLAGS) -w -c RobotPartTest.cpp
	$(CXX) $(CXXFLAGS) -o testLocomotor.out RobotPart.o Locomotor.o RobotPartTest.o
testBattery: Battery.o
	$(CXX) $(CXXFLAGS) -w -c BatteryTest.cpp
	$(CXX) $(CXXFLAGS) -o testBattery.out Battery.o BatteryTest.o
	
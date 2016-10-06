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

executable: main.o RobotPart.o Locomotor.o Battery.o Arm.o Head.o
	$(CXX) $(CXXFLAGS) main.o RobotPart.o Locomotor.o Battery.o Arm.o Head.o
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -w -c main.cpp
RobotPart.o: RobotPart.cpp
	$(CXX) $(CXXFLAGS) -w -c RobotPart.cpp
Locomotor.o: Locomotor.cpp
	$(CXX) $(CXXFLAGS) -w -c Locomotor.cpp
Battery.o: Battery.cpp
	$(CXX) $(CXXFLAGS) -w -c Battery.cpp
Arm.o: Arm.cpp
	$(CXX) $(CXXFLAGS) -w -c Arm.cpp
Head.o: Head.cpp
	$(CXX) $(CXXFLAGS) -w -c Head.cpp
	
clean:
	rm -f *.o *.out


# Tests
testAll: testRobotPart testLocomotor testBattery
	./testRobotPart.out
	./testLocomotor.out
	./testBattery.out

testRobotPart: RobotPart.o Locomotor.o
	$(CXX) $(CXXFLAGS) -w -c RobotPartTest.cpp
	$(CXX) $(CXXFLAGS) -o testRobotPart.out RobotPart.o Locomotor.o RobotPartTest.o
testLocomotor: Locomotor.o RobotPart.o
	$(CXX) $(CXXFLAGS) -w -c RobotPartTest.cpp
	$(CXX) $(CXXFLAGS) -o testLocomotor.out RobotPart.o Locomotor.o RobotPartTest.o
testBattery: Battery.o
	$(CXX) $(CXXFLAGS) -w -c BatteryTest.cpp
	$(CXX) $(CXXFLAGS) -o testBattery.out Battery.o BatteryTest.o
testArm: Arm.o Head.o
	$(CXX) $(CXXFLAGS) -w -c armheadtest.cpp
	$(CXX) $(CXXFLAGS) -o testArm.out Arm.o Head.o armheadtest.o
testHead: Arm.o Head.o
	$(CXX) $(CXXFLAGS) -w -c armheadtest.cpp
	$(CXX) $(CXXFLAGS) -o testArm.out Arm.o Head.o armheadtest.o
# Homework 5
# Robbie Robot Shop
# Michael Currie 
# Anna Cox 
# Rabab Antria 
# Ricardo Morales

CXXFLAGS = -std=c++11

OFILES = main.o RobotPart.o Locomotor.o Battery.o Arm.o Torso.o Customer.o SalesAssociate.o RobotModel.o

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable

executable: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -w -c main.cpp
RobotPart.o: RobotPart.cpp RobotPart.h
	$(CXX) $(CXXFLAGS) -w -c RobotPart.cpp
Locomotor.o: Locomotor.cpp Locomotor.h
	$(CXX) $(CXXFLAGS) -w -c Locomotor.cpp
Battery.o: Battery.cpp Battery.h
	$(CXX) $(CXXFLAGS) -w -c Battery.cpp
Arm.o: Arm.cpp Arm.h
	$(CXX) $(CXXFLAGS) -w -c Arm.cpp
Torso.o: Torso.cpp Torso.h
	$(CXX) $(CXXFLAGS) -w -c Torso.cpp
Customer.o: Customer.cpp Customer.h Order.o
	$(CXX) $(CXXFLAGS) -w -c Customer.cpp
SalesAssociate.o: SalesAssociate.cpp SalesAssociate.h Order.o
	$(CXX) $(CXXFLAGS) -w -c SalesAssociate.cpp
RobotModel.o: RobotModel.cpp RobotModel.h Head.h Locomotor.o Arm.o Battery.o Torso.o
	$(CXX) $(CXXFLAGS) -w -c RobotModel.cpp
Order.o: Order.cpp Order.h RobotModel.o Customer.o SalesAssociate.o
	$(CXX) $(CXXFLAGS) -w -c Orders.cpp
	
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
testArm: Arm.o
	$(CXX) $(CXXFLAGS) -w -c armheadtest.cpp
	$(CXX) $(CXXFLAGS) -o testArm.out Arm.o Head.o armheadtest.o
#include "RobotModel.h"


double RobotModel::getPrice() {

	return price;
}

string RobotModel::getName() {
	return name;
}

int RobotModel::getModelNumber() {
	return modelNumber;
}

double RobotModel::getPartsCost() {

	return partsCost;
}

void RobotModel::updatePrice(double newPrice) {

	price = newPrice;
}

void RobotModel::setDescription(string des) {
	description = des;
}
string RobotModel::getDescription() {
	return description;
}



void RobotModel::setTorso(Torso tor) {
	if (torso != NULL) throw partAlreadySet{};

	torso = tor.getPartNumber();
	maxBatteries = tor.max_batteries();
	partsCost += tor.getCost();
	totalWeight += tor.getWeight();


}

void RobotModel::setHead(Head part_head){
	if (head != NULL) throw partAlreadySet{};

	head = part_head.getPartNumber();
	partsCost += part_head.getCost();
	totalWeight += part_head.getWeight();



}

void RobotModel::addArm(Arm arm){
	if (numOfArms == 2) throw partAlreadySet{};

	arms.push_back(arm.getPartNumber());
	numOfArms++;
	partsCost += arm.getCost();
	totalWeight += arm.getWeight();

}

void RobotModel::setLocomotor(Locomotor loco) {
	if (locomotor != NULL) throw partAlreadySet{};
	locomotor = loco.getPartNumber();
	partsCost += loco.getCost();
	totalWeight += loco.getWeight();

}

void RobotModel::setBatteries(Battery batteries) {
	
	if (battery != NULL) throw partAlreadySet{};
	if (torso == NULL) throw noTorso{};

	battery = batteries.getPartNumber();
	partsCost += batteries.getCost()*maxBatteries;
	totalWeight += batteries.getWeight()*maxBatteries;
}

double RobotModel::getWeight() {

	return totalWeight;
}


int RobotModel::getTorso() {
    return torso;
}
int RobotModel::getHead()
{
    return head;
}
int RobotModel::getLocomotor(){
    return torso;
}
int RobotModel::getBattery(){
    return locomotor;
}
int RobotModel::getMaxBatteries(){
    return battery;
}
int RobotModel::getnumOfArms(){
    return numOfArms;
}
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

	torso = tor.getPartNumber();
	maxBatteries = tor.max_batteries();
	partsCost += tor.getCost();
	totalWeight += tor.getWeight();


}

void RobotModel::setHead(Head part_head){

	head = part_head.getPartNumber();
	partsCost += part_head.getCost();
	totalWeight += part_head.getWeight();



}

void RobotModel::addArm(Arm arm){

	arms.push_back(arm.getPartNumber());
	numOfArms++;
	partsCost += arm.getCost();
	totalWeight += arm.getWeight();

}

void RobotModel::setLocomotor(Locomotor loco) {
	
	locomotor = loco.getPartNumber();
	partsCost += loco.getCost();
	totalWeight += loco.getWeight();

}

void RobotModel::setBatteries(Battery batteries) {
	

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

void RobotModel::restoreValues(int itorso, int ihead, int ilocomotor, int ibattery, 
            string iname, string idescription, int imodelNumber, double iprice, int imaxBatteries,
            int inumOfArms, double ipartsCost,double itotalWeight) {
    
    int torso;
	head = ihead;
	locomotor = ilocomotor;
	battery = ibattery;
	name = iname;
	description = idescription;
	modelNumber = imodelNumber;
	price = iprice;
	maxBatteries = imaxBatteries;
	numOfArms = inumOfArms;
	partsCost  = ipartsCost;
	totalWeight = itotalWeight;
    
}
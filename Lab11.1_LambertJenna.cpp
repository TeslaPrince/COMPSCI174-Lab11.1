//Jenna Lambert
//Lab 11.1

//header files
#include "pch.h"
#include <iostream>
#include <string>

//namespace
using namespace std;

//class
class GasPump {
//prototypes
public:
	GasPump(double, double, double);
	void setRegular(double);
	void setSpecial(double);
	void setSuper(double);
	bool setGasType(int);
	double getGasPrice(double);
	double getRegular();
	double getSpecial();
	double getSuper();
	string getGasType();
private:
	double regular;
	double special;
	double super;
	int selectedType;
};

//~~Gas Pump~~
GasPump::GasPump(double regular, double special, double super) {
	regular = regular;
	special = special;
	super = super;
}

//~~Getters~~
double GasPump::getRegular() {
	return regular;
}
double GasPump::getSpecial() {
	return special;
}
double GasPump::getSuper() {
	return super;
}

//~~Setters~~
void GasPump::setRegular(double price) {
	regular = price;
}
void GasPump::setSpecial(double price) {
	special = price;
}
void GasPump::setSuper(double price) {
	super = price;
}
bool GasPump::setGasType(int gasNumber) {
	switch (gasNumber) {
	case 0:
		selectedType = gasNumber;
		break;
	case 1:
		selectedType = gasNumber;
		break;
	case 2:
		selectedType = gasNumber;
		break;
	default:
		return 1;
	}
	return 0;
}
double GasPump::getGasPrice(double gallons) {
	switch (selectedType) {
	case 0:
		return regular * gallons;
	case 1:
		return special * gallons;
	case 2:
		return super * gallons;
	default:
		cout << "Invalid gas type.\n";
		return -1;
	}
}

//~~Print Gas Options
void printGasOptions(double regPrice, double spePrice, double supPrice) {
	cout << "0 - Regular: $" << regPrice << endl;
	cout << "1 - Special: $" << spePrice << endl;
	cout << "2 - Super: $" << supPrice << endl;
}

//~~Main~~
int main()
{
    const double REGULAR = 2.54;
	const double SPECIAL = 2.89;
	const double SUPER = 2.99;
	int gasTypeNum;
	double gallons;
	GasPump localGasPump(REGULAR, SPECIAL, SUPER);
	printGasOptions(REGULAR, SPECIAL, SUPER);
	cout << "Select your gas type:";
	cin >> gasTypeNum;
	while (localGasPump.setGasType(gasTypeNum)) {
		cout << "Invalid gas type, please enter one of the options\n";
		printGasOptions(REGULAR, SPECIAL, SUPER);
		cout << "Enter gas type again:";
		cin >> gasTypeNum;
	}
	cout << localGasPump.getGasType() << " gasoline selected\n";
	cout << "Enter the desired gallons:";
	cin >> gallons;
	cout << "Your purchase of " << gallons << " gallons of " << localGasPump.getGasType()
		<< " gas at $" << localGasPump.getGasPrice(1) << " per gallon.\n";
	cout << "Your total cost is $" << localGasPump.getGasPrice(gallons);
	return 0;
}
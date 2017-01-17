/*
 * Throttle.cpp
 * Program to demonstrate classes
 *  Created on: Jan 15, 2017
 *      Author: William Ryan Clark
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;


// Function Prototype
void status(bool);


// Class to emulate a throttle
class Throttle {

private:
	int pos;
	int maxPos;


public:
	// Constructor 1
	Throttle(){
		pos = 0;
		maxPos = 6;
	}// End Constructor 1


	// Constructor 2
	Throttle(int mp){
		assert(mp > 0);
		pos = 0;
		maxPos = mp;
	}// End Constructor 2


	// Constructor 3
	Throttle(int mp, int p){
		assert(mp > 0);
		assert(p >= 0);
		pos = p;
		maxPos = mp;
	}// End Constructor 3


	//Shut off method
	void ShutOff(){
		pos = 0;
	}// End ShutOff method


	// Shift method
	void Shift(int val){
		pos += val;

		if (pos < 0){
			pos = 0;
		}// End if
		else if (pos > maxPos){
			pos = maxPos;
		}// End else if
	}// End Shift method


	// Flow method
	double Flow() const {
		return (double)pos / (double)maxPos;
	}// End Flow method


	// Is on method
	bool IsOn() const {
		return Flow() > 0;
	}// End IsOn method
};// End Throttle Class


//Function to display status
void status(bool s){
	if (s){
		cout << "Hey I'm On!\n";
	}// End if
	else{
		cout << "Hey I'm Off!\n";
	}// End else
}// End status function


// Main program
int main(){

	// Create objects
	Throttle LM, Truck(18), SpaceShuttle(100, 1);

	// Test the Lawn Mower object using the default constructor
	cout << "Mower:\n";
	cout << "Checking to see if the mower is on...\n";
	status(LM.IsOn());
    cout << "\nShifting below zero...\n";
    LM.Shift(-1);
    cout << setprecision(3) << LM.Flow() * 100 << "% Throttle\n";
    cout << "\nShifting above six...\n";
    LM.Shift(10);
    cout << setprecision(3) << LM.Flow() * 100 << "% Throttle\n";
    cout << "\nChecking to see if the mower is on...\n";
    status(LM.IsOn());
    cout << "\nShifting down one gear...\n";
    LM.Shift(-1);
    cout << setprecision(3) << LM.Flow() * 100 << "% Throttle\n";
    cout << "\nShutting off the mower...\n";
    LM.ShutOff();
    status(LM.IsOn());


    // Test the Truck object using constructor 2 to set the max position
    cout << "\n\nTruck:\n";
    cout << "Checking to see if the Truck is on...\n";
    status(Truck.IsOn());
    cout << "\nShifting below zero...\n";
    Truck.Shift(-1);
    cout << setprecision(3) << Truck.Flow() * 100 << "% Throttle\n";
    cout << "\nShifting above 18...\n";
    Truck.Shift(20);
    cout << setprecision(3) << Truck.Flow() * 100 << "% Throttle\n";
    cout << "\nChecking to see if the Truck is on...\n";
    status(Truck.IsOn());
    cout << "\nShifting down five gears...\n";
    Truck.Shift(-5);
    cout << setprecision(3) << Truck.Flow() * 100 << "% Throttle\n";
    cout << "\nShutting off the Truck...\n";
    Truck.ShutOff();
    status(Truck.IsOn());


    // Test the SpaceShuttle object using constructor 3 to set the default position and max position
    cout << "\n\nSpace Shuttle:\n";
    cout << "Checking to see if the Space Shuttle is on...\n";
    status(SpaceShuttle.IsOn());
    cout << "\nShifting below zero...\n";
    SpaceShuttle.Shift(-2);
    cout << setprecision(3) << SpaceShuttle.Flow() * 100 << "% Throttle\n";
    cout << "\nShifting above 100...\n";
    SpaceShuttle.Shift(200);
    cout << setprecision(3) << SpaceShuttle.Flow() * 100 << "% Throttle\n";
    cout << "\nChecking to see if the Space Shuttle is on...\n";
    status(SpaceShuttle.IsOn());
    cout << "\nShifting down 35 gears...\n";
    SpaceShuttle.Shift(-35);
    cout << setprecision(3) << SpaceShuttle.Flow() * 100 << "% Throttle\n";
    cout << "\nShutting off the Space Shuttle..\n";
    SpaceShuttle.ShutOff();
    status(SpaceShuttle.IsOn());

    return 0;
}// End Main


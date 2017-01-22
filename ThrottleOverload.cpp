/*
 * ThrottleOverload.cpp
 * Program that demonstrates operator overloading
 *  Created on: Jan 20, 2017
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


	// Copy Constructor
	Throttle(Throttle &cpy){
		pos = cpy.pos;
	    maxPos = cpy.maxPos;
	}// End Copy Constructor


	//Shut off method
	void ShutOff(){
		pos = 0;																																																																	pos = 0;
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


	// Method to overload the == operator
	bool operator ==(const Throttle &t1){
		return
			(t1.maxPos == maxPos)
		&&
			(t1.pos == pos);
	}// End == overload method


	//friend function prototype
	friend ostream& operator << (ostream &out, const Throttle &t);
};// End Throttle Class


// Method prototype to overload the != operator
bool operator !=(Throttle&, Throttle&);


// Member function to overload the != operator
bool operator!=(Throttle &t1, Throttle &t2){
	return !(t1 == t2);
}// End operator!= method


//Function to display status
void status(bool s){
	if (s){
		cout << "Hey I'm On!\n";
	}// End if
	else{
		cout << "Hey I'm Off!\n";
	}// End else
}// End status function


//Friend function
ostream& operator << (ostream &out, const Throttle &t){
    out << t.pos << "         " << t.maxPos;
    return out;
}// End << function


// Main program
int main(){

	// Create objects
	Throttle Car, Truck(30), SpaceShuttle(20, 6), myThrottle(Truck);
	/*
	// Test the Lawn Mower object using the default constructor
	cout << "Car:\n";
	cout << "Checking to see if the car is on...\n";
	status(Car.IsOn());
    cout << "\nShifting below zero...\n";
    Car.Shift(-1);
    cout << setprecision(3) << Car.Flow() * 100 << "% Throttle\n";
    cout << "\nShifting above six...\n";
    Car.Shift(10);
    cout << setprecision(3) << Car.Flow() * 100 << "% Throttle\n";
    cout << "\nChecking to see if the car is on...\n";
    status(Car.IsOn());
    cout << "\nShifting down one gear...\n";
    Car.Shift(-1);
    cout << setprecision(3) << Car.Flow() * 100 << "% Throttle\n";
    cout << "\nShutting off the car...\n";
    Car.ShutOff();
    status(Car.IsOn());


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
	*/

    // Testing ==
    cout << "\nComparing (==) myThrottle and Truck using the explicit call..\n";
    if (Truck.operator==(myThrottle)){
    	cout << "Match!\n";
    }// End if
    else{
    	cout << "No Match!\n";
    }// End else

    cout << "\nComparing (==) myThrottle and Truck using the implicit call..\n";
    if (Truck == myThrottle){
    	cout << "Match!\n";
    }// End if
    else{
    	cout << "No Match!\n";
    }// End else

    cout << "\nComparing (==) myThrottle and Car using the explicit call..\n";
    if (Car.operator==(myThrottle)){
      	cout << "Match!\n";
    }// End if
    else{
       	cout << "No Match!\n";
    }// End else

    cout << "\nComparing (==) myThrottle and Car using the implicit call..\n";
    if (Car == myThrottle){
       	cout << "Match!\n";
    }// End if
    else{
      	cout << "No Match!\n";
    }// End else


    //Testing !=
    cout << "\nComparing (!=) myThrottle and Truck using the explicit call..\n";
        if (operator!=(myThrottle, Truck)){
        	cout << "No Match!\n";
        }// End if
        else{
        	cout << "Match!\n";
        }// End else

        cout << "\nComparing (!=) myThrottle and Truck using the implicit call..\n";
        if (myThrottle != Truck){
        	cout << "No Match!\n";
        }// End if
        else{
        	cout << "Match!\n";
        }// End else

        cout << "\nComparing (!=) myThrottle and Car using the explicit call..\n";
        if (operator!=(myThrottle, Car)){
          	cout << "No Match!\n";
        }// End if
        else{
           	cout << "Match!\n";
        }// End else

        cout << "\nComparing (!=) myThrottle and Car using the implicit call..\n";
        if (myThrottle != Car){
           	cout << "No Match!\n";
        }// End if
        else{
          	cout << "Match!\n";
        }// End else


        //Print out Throttle positions
        cout << "\nTruck:\nStart     " << "Max\n";
        cout << Truck << "\n";

        //Print out Throttle positions
        cout << "\nmyThrottle:\nStart     " << "Max\n";
        cout << myThrottle << "\n";


        //Print out Throttle positions
        cout << "\nCar:\nStart     " << "Max\n";
        cout << Car << "\n";


        //Print out Throttle positions
        cout << "\nSpace Ship:\nStart     " << "Max\n";
        cout << SpaceShuttle << "\n";

    return 0;
}// End Main





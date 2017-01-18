/*
 * Points.cpp
 * Program to demonstrate classes using xyz coordinates
 *  Created on: Jan 16, 2017
 *      Author: William Ryan Clark
 */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


// Point Class
class Point{
private:
	double x, y, z;

public:
	// Constructor
	Point(){
		x = 2.5;
		y = 0;
		z = 2;
	}// End Constructor


	// Set method
	void Set(double inX, double inY, double inZ){
		x = inX;
		y = inY;
		z = inZ;
	}// End Set method


	// Get method
	double Get(char c){
		if (c == 'x'){
			return x;
		}// End if
		else if (c == 'y'){
			return y;
		}// End else if
		else{
			return z;
		}// End else
	}// End Get method


	// Shift method
	void Shift(double sX, double sY, double sZ){
		x += sX;
		y += sY;
		z += sZ;
	}// End Shift method


	// Rotate method
	void Rotate(char axis, int degs){
		// Convert degrees to radians
		double rad = (degs * M_PI) / 180;

		if (axis == 'x'){
			y = y * cos(rad) - z * sin(rad);
			z = y * sin(rad) + z * cos(rad);
		}// End if
		else if (axis == 'y'){
			x = x * cos(rad) + z * sin(rad);
			z = -x * sin(rad) + z * cos(rad);
		}// End else if
		else{
			x = x * cos(rad) - y * sin(rad);
			y = x * sin(rad) + y * cos(rad);
		}// End else
	}// End Rotate method
};// End Point Class


// Main program
int main(){
	// Variables
	double mX, mY, mZ, degrees;
	char axis;

	// Create object
	Point test;

	cout << "Starting Values:\n" << test.Get('x') << "," << test.Get('y') << "," << test.Get('z') << "\n\n";

	cout << "Enter the amount you would like to move the point in x y z format (e.g. 1 0 2)";
	cin >> mX >> mY >> mZ;

	test.Shift(mX, mY, mZ);

	cout << "New Values:\n" << test.Get('x') << "," << test.Get('y') << "," << test.Get('z') << "\n\n";

	test.Set(2.5, 0, 2);// Set back to Starting Values

	cout << "Back to Starting Values:\n" << test.Get('x') << "," << test.Get('y') << "," << test.Get('z') << "\n";

	cout << "Enter the axis and degrees to rotate (e.g. x 60):\n";
	cin >> axis >> degrees;

	test.Rotate(axis, degrees);

	cout << "New Values:\n" << test.Get('x') << "," << test.Get('y') << "," << test.Get('z') << "\n\n";

	return 0;
}// End main

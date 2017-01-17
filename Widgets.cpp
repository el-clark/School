/*
 * Widgets.cpp
 * Program to demonstrate creating objects with a class
 *  Created on: Jan 15, 2017
 *      Author: William Ryan Clark
 */

#include <iostream>
#include <iomanip>
using namespace std;


// Widget Factory Class
class WF{
private:
	int widgets;
	double days;
	int hrs;
	int wPerHr;

public:
	WF(){
		widgets = 0;
		days = 0;
		hrs = 16;
		wPerHr = 10;
	}// End constructor


	// Set Widgets method
	void setW(int w){
		widgets = w;
	}// End setW function


	// Get Widgets method
	int getW(){
		return widgets;
	}// End getW method


	// Calculate days
	double calcDays(int w){
		days = (double)widgets / (double)(hrs * wPerHr);
		return days;
	}// End calcDays
};



// Main Program
int main(){
	// Variables
	int input;

	// Create object
	WF order1;


	do {
		cout << "How many widgets would you like order?";
		cin >> input;
	}while(input < 1);

	order1.setW(input);
	cout << "It will take " << setprecision(2) << order1.calcDays(order1.getW()) << " day(s) to make your order.";
	return 0;
}// End main program




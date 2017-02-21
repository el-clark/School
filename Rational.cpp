/*
 * Rational.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: William Ryan Clark
 */


#include <iostream>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <sstream>
using namespace std;

class RN{

private:
	int n, d;

public:
	// Default Constructor
	RN(){
		n = 0;
		d = 0;
	}// End Default Constructor


	// Custom Constructor
	RN(int num, int den){
		n = num;
		d = den;
	}// End Custom Constructor


	// Method to add two Rational objects
	void add(RN obj1, RN obj2){
		n = (obj1.n * obj2.d) + (obj1.d * obj2.n);
		d = (obj1.d * obj2.d);
	}// End add method


	// Method to multiply two Rational objects
	void mult(RN obj1, RN obj2){
		n = (obj1.n * obj2.n);
		d = (obj1.d * obj2.d);
	}// End mult method


	// Method to divide two Rational objects
	void div(RN obj1, RN obj2){
		n = (obj1.n  * obj2.d);
		d = (obj1.d * obj2.n);
	}// End divide


	// Method to subtract two Rational objects
	void sub(RN obj1, RN obj2){
		n = (obj1.n * obj2.d) - (obj1.d * obj2.n);
		d = (obj1.d * obj2.d);
	}// End sub method


	// Method to print
	void print(){
		cout << n << "/" << d;
	}// End print method


	// Overload <<
	friend ostream& operator << (ostream &out, const RN &R){
		out << R.n << "/" << R.d;
		return out;
	}// End << overload


	// Method to overload the == operator
	bool operator ==(const RN &R){
		return (n == R.n && d == R.d);
	}// End == overload method


	// Method to overload the == operator
	bool operator !=(const RN &R){
		return (n != R.n || d != R.d);
	}// End == overload method
};// End Rational Number Class


// Main
int main(){
	// Create objects
	RN a(3, 8);
	RN b(4, 7);
	RN c(1, 5);
	RN d(4, 12);
	RN e(3, 5);
	RN f(4, 1);
	RN g(3, 0);


	// Add
	RN sum;
	sum.add(a, b);
	cout << "Sum:\n" << a << " + " << b << " = " << sum;


	// Multiply
	RN product;
	product.mult(c, d);
	cout << "\n\nProduct:\n" << c << " * " << d << " = " << product;


	// Divide
	RN quotient;
	quotient.div(d, e);
	cout << "\n\nQuotient:\n" << d << " / " << e << " = " << quotient;


	// Subtract
	RN difference;
	difference.sub(c, a);
	cout << "\n\nDifference:\n" << c << " - " << a << " = " << difference;


	// a+b*f-d
	RN aa, ba, ans1;
	aa.add(a, b);
	ba.sub(f, d);
	ans1.mult(aa, ba);
	cout << "\n\na+b*f-d = " << ans1;


	// d/a+c
	RN ab, ans2;
	ab.div(d, a);
	ans2.add(ab, c);
	cout << "\n\nd / a + c = " << ans2;

	// Print g
	cout << "\n\ng:\n" << g;


	// Compare two objects
	cout << "\n\nComparing " << d << " to " << b << "\n";
	if (d == b){
		cout << d << " equals " << b << "\n";
	}// End if
	else{
		cout << d << " does not equal " << b << "\n";
	}// End else


	// Compare two objects
	cout << "\n\nComparing " << e << " to " << a << "\n";
	if (e != a){
		cout << e << " does not equal " << a << "\n";
	}// End if
	else{
		cout << e << " equals " << a << "\n";
	}// End else


}// End main

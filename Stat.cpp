/*
 * Stat.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: William Ryan Clark
 */


#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;

// Statistician class
class statistician{
private:
	double length, sum, sm, lg;

public:
	//Default constructor
	statistician(){
		length = 0;
		sum = 0;
		sm = 0;
		lg = 0;
	}// End default constructor


	//Copy constructor
	statistician(statistician &cpy){
		length = cpy.length;
		sum = cpy.sum;
		lg = cpy.lg;
		sm = cpy.sm;
	}// End copy constructor


	//Default constructor
	void erase(){
		length = 0;
		sum = 0;
		sm = 0;
		lg = 0;
	}// End erase method


	//Method to check for the largest number
	void chk_lg(double N){
		if (N > lg){
			lg = N;
		}// End if
	}// End chk_lg method


	//Method to check for the smallest number
	void chk_sm(double N){
		if (N < sm){
			sm = N;
		}// End if
	}// End chk_sm method


	// Next_number method
	void next_number(double N){
		sum += N;
		length ++;
		chk_lg(N);
		chk_sm(N);
	}// End next_number method


	//Get sum method
	double get_sum(){
		return sum;
	}// End get sum method


	//Get length method
	double get_length(){
		return length;
	}// End get length method


	//Get smallest
	double get_sm(){
		return sm;
	}// End get_sm method


	//Get largest
	double get_lg(){
		return lg;
	}// End get_lg method


	//Set length
	void set_length(double L){
		length = L;
	}// End set_length method


	//Set sum
	void set_sum(double S){
		sum = S;
	}// End set_sum method


	//Set largest
	void set_lg(double Lg){
		lg = Lg;
	}// End set_lg method


	//Set smallest
		void set_sm(double Sm){
			sm = Sm;
		}// End set_sm method


	// Method to overload the == operator
	bool operator ==(const  statistician &s1){
		return (s1.sum == sum && s1.length == length && s1.sm == sm && s1.lg == lg);
	}// End == overload method


	// Method to overload the != operator
	bool operator !=(const  statistician &s1){
		return !(s1.sum == sum && s1.length == length && s1.sm == sm && s1.lg == lg);
	}// End != overload method


	//Friend function for <<
	friend ostream& operator <<(ostream &out, const statistician &stat){
		out << "Sum: " << stat.sum << "\nLength: " << stat.length << "\n";
		return out;
	}// End << friend function
};// End statistician class


//Function outside of class to add to objects...overloaded +
statistician operator +(statistician &s1, statistician &s2){
	statistician s3;
	s3.set_length(s1.get_length() + s2.get_length());
	s3.set_sum(s1.get_sum() + s2.get_sum());
	if (s1.get_lg() > s2.get_lg()){
		s3.set_lg(s1.get_lg());
	}// End if
	else{
		s3.set_lg(s2.get_lg());
	}// End else

	if (s1.get_sm() < s2.get_sm()){
		s3.set_sm(s1.get_sm());
	}// End if
	else{
		s3.set_sm(s2.get_sm());
	}// End else
	return s3;
}// End + function


// Main program
int main(){
//create objects
statistician stat1, stat3;

//Add data to stat1
stat1.next_number(5.5);
stat1.next_number(6.6);
stat1.next_number(8.8);
stat1.next_number(-3.4);
stat1.next_number(-0.5);
stat1.next_number(4.7);
stat1.next_number(9.1);

//Print out using getter methods
cout << "Statistician 1:\nData set 1:\n" << "Sum: " << stat1.get_sum() << "\nLength: " << stat1.get_length()
	 << "\nAverage: " << stat1.get_sum() / stat1.get_length() << "\n\n";

//Add more data to stat1
stat1.next_number(5.2);
stat1.next_number(-3.3);
stat1.next_number(-8.5);
stat1.next_number(3.2);
stat1.next_number(5.5);

//Print out using << operator
cout << "Statistician 1:\nData set 2:\n" << stat1 << "Average: " << stat1.get_sum() / stat1.get_length() << "\n\n";

//Copy an object
statistician stat2(stat1);
cout << "Copying statistician 1 to a new statistician 2:\nStatistician 1:\n" << stat1 << "\nStatistician 2:\n"
	 << stat2 << "\n\n";

//Add more data to stat2
stat2.next_number(13);
stat2.next_number(21);
stat2.next_number(71);
stat2.next_number(47);
stat2.next_number(12);
stat2.next_number(25);
stat2.next_number(24);
stat2.next_number(23);
stat2.next_number(24);
stat2.next_number(32);

//Print out Stat2
cout << "Statistician 2:\nData set1:\n" << "Sum: " << stat2.get_sum() << "\nLength: " << stat2.get_length()
			 << "\nAverage: " << stat2.get_sum() / stat2.get_length() << "\n\n";

//Printing out Stat2 and Stat1 with <<
cout << "Statistician 1:\n" << stat1 << "\nStatistician 2:\n"
		 << stat2 << "\n\n";

cout << "Adding two statisticians together (stat1 + stat2):\n";
stat3 = stat1 + stat2;

//Print all three statisticians
cout << "Statistician 1:\n" << stat1 << "\nStatistician 2:\n" << stat2 << "\nStatistician 3:\n" << stat3;

cout << "\n\nErasing statistician 2:\n";
stat2.erase();

//Print all three statisticians
cout << "Statistician 1:\n" << stat1 << "\nStatistician 2:\n" << stat2 << "\nStatistician 3:\n" << stat3;
}// End main program



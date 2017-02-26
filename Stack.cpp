/*
 * Stack.cpp
 *  Program that reads in  char and checks for matches
 *  Created on: Feb 11, 2017
 *      Author: William Ryan Clark
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <sstream>
using namespace std;


//List class
class List{

public:
	// define typdefs and constants
	typedef char ElementType;
	static const size_t CAPACITY = 1000;

	// Default constructor
	List(){
		ARY[CAPACITY] = {0};
		pos = 0;
		used = 0;
		count = 0;
	}// End default constructor

	// Copy constructor
	List(const List &cpy){
		pos = cpy.pos;
		used = cpy.used;
		count = cpy.count;

		for (size_t i = 0; i < CAPACITY; i++){
			ARY[i] = cpy.ARY[i];
		}// End for loop
	}// End copy constructor

	// Method to tell if list is empty
	bool empty(){
		return (count == 0);
	}// End empty method

	// Moves current position to the beginning of the list
	void first(){
		pos = 0;
	}// End first method

	// Moves current position to the end of the list
	void last(){
		if (used != 0){
			pos = used - 1;
		}// End if
	}// End last method

	// Moves current position to the previous element
	bool prev(){
		if (pos > 0){
			pos--;
			return 0;// Return 0, successful
		}// End if
		else{
			return 1;// Return non zero value for error
		}// End else
	}// End prev method

	// Moves the current position to the next element
	bool next(){
		if (pos < used){
			pos++;
			return 0;
		}// End if
		else{
			return 1;// Return non zero value for error
		}// End else
	}// End next method

	// Returns current position
	size_t getPos(){
		return pos;
	}// End getPos method

	// Moves the current position to a specified location
	bool setPos(size_t p){
		if (p < CAPACITY && p >= 0){
			pos = p;
			return 0;// Return zero for successful
		}// End if
		else{
			return 1;// Return non zero value for error
		}// End else
	}// End setPos method

	// Insert Before method
	bool insertBefore(ElementType val){
		if (pos < CAPACITY - 1){
			count++;
			ARY[CAPACITY - count] = val;
			if (count != CAPACITY){
				next();
				used++;
			}// End if
			return 0;// Return zero for successful
		}// End if
		return 1;// Return non zero value for error
	}// End insertBefore

	// Inserts a new element after the current position
	bool insertAfter(ElementType val){

		if (pos < CAPACITY - 1){
			if (count == 0){
				count++;
				ARY[used] = val;
				used++;
			}// End if
			else{
				ARY[used] = val;
				used++;
				pos++;
				count++;
			}// End else
			return 0; // Return zero for successful
		}// End if
		return 1;// Return non zero value for error
	}// End insertAfter method

	// Get value at current position
	ElementType getElement(){
		assert(pos >= 0 && pos <= CAPACITY);
		return ARY[pos];
	}// End getElement method

	// Returns the number of items in a list
	size_t size(){
		return count;
	}// End size method

	// Replace the current element with a new value
	void replace(ElementType v){
		ARY[pos] = v;
	}// End replace method

	// Deletes the current element
	void erase(){
		for (size_t i = pos; i < used; i++){
			if (i == used){
				ARY[i] = 0;
			}// End if
			else{
				ARY[i] = ARY[i+1];
			}// End else
		}// End for loop
		if (count != 0){
			count--;
			used--;
		}// End if
	}// End erase method

	// Makes the list empty
	void clear(){
		ARY[CAPACITY] = {0};
		pos = 0;
		used = 0;
		count = 0;
	}// End clear method

	// Overload <<
	friend ostream& operator << (ostream &out, const List &L){
		for (size_t i = 0; i < L.used + 1; i++){
			out << L.ARY[i] << " ";
		}// End for loop
		    return out;
	}// End << overload

	// Method to overload the == operator
	bool operator ==(const List &L){
		if (L.count != count){
			return (L.count == count);
		}// End if

		for (size_t i = 0; i < CAPACITY; i++){
			if (L.ARY[i] != ARY[i]){
				return (L.ARY[i] == ARY[i]);
			}// End if
		}// End for loop

		return true;
	}// End == overload method

	// Overload +
	List operator +(const List &L2){
		List L3;

		int size1 = count;
		int size2 = L2.count;

		if ((count + L2.count) < CAPACITY){
			for (int i = 0; i < size1 + size2; i++){
				if (i < size1){
					L3.ARY[i]=ARY[i];
					L3.used++;
					L3.pos++;
					L3.count++;
				}// End if
				else{
			        L3.ARY[i] = L2.ARY[i-size1];
			        L3.used++;
			        L3.pos++;
			        L3.count++;
				}// End else
			}// End for loop
		}// End if
		return L3;
	}// End + overload

private:
ElementType ARY[CAPACITY];
size_t pos, used, count;
};// End List class


// Stack class
class stack{
private:
	List MyStack;

public:
	typedef char ElementType;

	// Method to insert a value into the stack
	bool push(ElementType val){
		if (MyStack.size() < MyStack.CAPACITY){
			MyStack.last();
			return MyStack.insertAfter(val);
		}// End if
		else{
			return 1;// return non-zero for error
		}// End else
	}// End push method

	// Method to delete the current element in a stack
	void pop(){
		//MyStack.last();
		MyStack.erase();
	}// End pop method


	// Method that returns a pointer to the first element in the Stack
	ElementType top(){
		MyStack.last();
		return MyStack.getElement();
	}// End top method


	// Method to tell if the list is empty
	bool IsEmpty(){
		return (MyStack.empty());
	}// End IsEmpty method

	// Method that returns the size of the list
	size_t size(){
		return MyStack.size();
	}// End size method


	// Method to print the stack
	void Print(){
		MyStack.first();
		for (size_t i = 0; i < MyStack.size(); i++){
			cout << MyStack.getElement();
			MyStack.next();
		}// End for loop
	}// End Print method


	// Method to match input and the top of the stack
	bool match(ElementType v){
		if (v == ')'){
			if (top() == '('){
				return 1;// Return 1 for true
			}// End if
		}// End if

		if (v == ']'){
			if (top() == '['){
				return 1; // Return 1 for true
			}// End if
		}// End if

		if (v == '}'){
			if (top() == '{'){
				return 1;// Return 1 for true
			}// End if
		}// End if

		if (v == '>'){
			if (top() == '<'){
				return 1;// Return 1 for true
			}// End if
		}// End if
		return 0;// Return 0 for false
	}// End match method
};// end Stack class


// Main program
int main(){
	// Input file0
	string inPath0 = "/home/ryan/pgm_input/LispClassData0.txt";
	ifstream inFile0 (inPath0.c_str());

	// Input file1
	string inPath1 = "/home/ryan/pgm_input/LispClassData.txt";
	ifstream inFile1 (inPath1.c_str());

	// Input file2
	string inPath2 = "/home/ryan/pgm_input/LispClassData2.txt";
	ifstream inFile2 (inPath2.c_str());

	// Input file3
	string inPath3 = "/home/ryan/pgm_input/Stack3.dat";
	ifstream inFile3 (inPath3.c_str());

	stack A, B, C, D;
	char c;


	while(inFile0.get(c)){
			if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>'){
				//cout << c << "\n";
				if (A.IsEmpty()){
					A.push(c);
				}// End if
				else{
					if (A.match(c)){
						A.pop();
						//cout << "match\n";
					}// End else
					else{
						A.push(c);
						//cout << "does not match\n";
					}// End if
				}// End else
			}// End else
		}// End while loop

		cout << "File0:\n";
		if (A.IsEmpty()){
			cout << "Matching\n";
		}// End if
		else{
			cout << "Not matching\n";
			cout << "Extra value(s): ";A.Print();
		}// End else


	while(inFile1.get(c)){
		if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>'){
			//cout << c << "\n";
			if (B.IsEmpty()){
				B.push(c);
			}// End if
			else{
				if (B.match(c)){
					B.pop();
					//cout << "match\n";
				}// End else
				else{
					B.push(c);
					//cout << "does not match\n";
				}// End if
			}// End else
		}// End else
	}// End while loop

	cout << "\n\nFile1:\n";
	if (B.IsEmpty()){
		cout << "Matching\n";
	}// End if
	else{
		cout << "Not matching\n";
		cout << "Extra value(s): ";B.Print();
	}// End else


	while(inFile2.get(c)){
		if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>'){
			//cout << c << "\n";
			if (C.IsEmpty()){
				C.push(c);
			}// End if
			else{
				if (C.match(c)){
					C.pop();
					//cout << "match\n";
				}// End else
				else{
					C.push(c);
					//cout << "does not match\n";
				}// End if
			}// End else
		}// End else
	}// End while loop

	cout << "\n\nFile2:\n";
	if (C.IsEmpty()){
		cout << "Matching\n";
	}// End if
	else{
		cout << "Not matching\n";
		cout << "Extra value(s): ";C.Print();
	}// End else


	while(inFile3.get(c)){
		if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>'){
			//cout << c << "\n";
			if (D.IsEmpty()){
				D.push(c);
			}// End if
			else{
				if (D.match(c)){
					D.pop();
					//cout << "match\n";
				}// End else
				else{
					D.push(c);
					//cout << "does not match\n";
				}// End if
			}// End else
		}// End else
	}// End while loop

	cout << "\n\nFile3:\n";
	if (D.IsEmpty()){
		cout << "Matching\n";
	}// End if
	else{
		cout << "Not matching\n";
		cout << "Extra value(s): ";D.Print();
	}// End else
	return 0;
}// End main program





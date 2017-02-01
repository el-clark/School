/*
 * List.cpp
 * Program to demonstrate a list
 *  Created on: Jan 28, 2017
 *      Author: William Ryan Clark
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;



//List class
class List{

public:
	// define typdefs and constants
	typedef int ElementType;
	static const size_t CAPACITY = 20;

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
		pos = CAPACITY - 1;
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

		if (pos < CAPACITY -1){
			if (count == 0){
				count++;
				ARY[pos] = val;
			}// End if
			else{
				used++;
				pos++;
				count++;
				ARY[pos] = val;
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


// Main program
int main(){

	List a,b;  int endit;

		for (int i=1;i<=20;i++)
		   a.insertAfter(i);
		cout << "List a : " << endl;
	    cout << "  "  << a << endl;
		cout << "Number of elements in a - " << a.size() << endl;

		for (int i=1;i<=20;i++)
		   b.insertBefore(i);
		cout << "List b : " << endl;
	    cout << "  "  <<  b << endl;
		cout << "Number of elements in b - " << b.size() << endl;

		if ( a == b )
		    cout << "List a & b are equal" << endl;
		  else
		    cout << "List a & b are Not equal" << endl;

		a.first();
		b.first();
		cout << "First elmenet in list a & b: " << a.getElement() << ", "
					       << b.getElement() << endl;
		for ( int i = 0; i < a.size(); a.next(),i++);
		for ( int i = 0; i < b.size(); b.next(),i++);
		cout << "Last elmenet in list a & b: " << a.getElement() << ", "
					     << b.getElement() << endl;
		cout << endl << endl << " Start of new stuff" << endl;

		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		a.first();
		b.first();
		endit = a.size()/2;
		for ( int i = 1; i<endit; i++)
		{  a.next();
		   b.next();
		}

		a.last();
		b.last();
		a.insertAfter(100);
		a.insertBefore(99);
		cout << " Test last " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		cout << "New position in Obj 'a' position = " << a.size()/2 << endl;

		for ( int i=1; i<8; i++)
		{
		   a.erase();
		   b.replace(i);
		}

		cout << "Modified Object 'a' " << endl;
	    cout << "List a: " << a << endl;

		List c(b);
		cout << "Copy Constructor c(b)" << endl;
	    cout << "List b : " << b << endl;
	    cout << "List c : " << c << endl;

		if ( c == b )
		    cout << "List c & b are equal" << endl;
		  else
		    cout << "List c & b are Not equal" << endl;


		List e;
		e = c;
		cout << "Object 'c' assigned to Object 'e':" << endl;
	    cout << "List c : " << c << endl;
	    cout << "List e : " << e << endl;

	    List d;
		d=a;
		d.first();
		endit = d.size()/2;
		for (int i=1; i<=endit; i++)
		{
			d.next();
			d.erase();
		}
		cout << "Results after some erases: Object d  " << endl;
	    cout << "List d : " << d << endl;

		d.first();
		endit = d.size();
		for ( int i = 1; i < endit; d.next(), i++)
		{
			d.insertBefore(d.getElement()*2);
			d.next();
		}
		cout << "Results after some Replaces on d " << endl;
	    cout << "List d : " << d << endl;

		a.first();
		endit = a.size();
		for ( int i = 1; i < endit; a.next(), i++)
		{
			a.insertBefore(a.getPos()+a.getElement());
			a.next();
			a.erase();
		}
		cout << "Results after some weird stuff on list a" << endl;
	    cout << "List a : " << a << endl;

	    List alist(b);
	    alist.clear();
	    for (int i=1;i<=10;i++)
		   alist.insertAfter(i);
		alist.first();
		cout << "New List alist with positions above: " << endl;
	    for (int i=1;i<=10;i++) {
			cout << setw(5) << alist.getPos();
			alist.next();
		}
		cout << endl;
		alist.first();
		for (int i=1;i<=10;i++) {
			cout << setw(5) << alist.getElement();
			alist.next();
		}
		cout << endl;

	    List newa;
	    for (int i=1;i<=20;i++)
		   newa.insertAfter(i*3);
	    cout << "List alist and newa before swap " << endl;
	    cout << " " << alist << endl;
	    cout << " " << newa << endl;

		cout << endl << "  check out boundary conditions" << endl;
		List sq;
		cout << "number of elements in empty sq list = " << sq.size() << endl;
		sq.first();
		sq.erase();
		cout << "empty sq values " << sq << endl;
		sq.insertBefore(999);
		cout << "sq values " << sq << endl;
		sq.next(); sq.next();
		cout << "sq.getElement() = " << sq.getElement() << endl;
		cout << "sq values " << sq << endl;
	return 0;
}// End main program

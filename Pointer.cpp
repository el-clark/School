/*
 * Pointer.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: ryan
 */



#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
void table_print(int*, int);    //print array of size sz
void table_add1(int*, int);    //add one to every element in array of size sz
void table_fill(int*, int, int);   //fill array with value v of size sz
void table_print_rev(int*, int);   //print array in reverse order of size sz
void table_copy(int*, int*, int);  //copy array s data in to array r of size sz
int table_min(int*, int);   //min value of array of size sz
int table_max(int*, int);    //max value of array of size sz
int table_sum(int*, int);   //sum of array of size sz
int table_avg(int*, int);   //average of array of size sz
int * table_contain(int*, int, int); //compare to see if v is in the array of size sz.


// Function to fill an array
void table_fill(int *p, int sz, int v){
	for (int i = 0; i < sz; i++){
		*p = v;
		p++;
	}// End for loop
}// End table_fill


// Function to print an array
void table_print(int *p, int sz){
	for (int i = 0; i < sz; i++){
		cout << *p << " ";
		p++;
	}// End for loop
}// End table_print


// Function to add 1 to each value in the array
void table_add1(int *p, int sz){
	for (int i = 0; i < sz; i++){
		*p += 1;
		p++;
	}// End for loop
}// End table_add1


// Function to print an array in reverse
void table_print_rev(int *p, int sz){
	int *tmp;
	tmp = p;
	for (p += (sz - 1); p >= tmp; p--){
		cout << *p << " ";
	}// End for loop
}// End table_print_rev


// Function to copy an array to another array
void table_copy(int *r, int *s, int sz){
	for (int i = 0; i < sz; i++){
		*r = *s;
		r++;
		s++;
	}// End for loop
}// End table_copy


// Function to find the smallest value in the array
int table_min(int *p, int sz){
	int small = *p;
	for (int i = 0; i < sz; i++){
		if (*p < small){
			small = *p;
		}// End if
		p++;
	}// End for loop
	return small;
}// End table_min


// Function to find the largest value in the array
int table_max(int *p, int sz){
	int large = *p;
	for (int i = 0; i < sz; i++){
		if (*p > large){
			large = *p;
		}// End if
		p++;
	}// End for loop
	return large;
}// End table_max


// Function to get the sum of an array
int table_sum(int *p, int sz){
	int sum = 0;
	for (int i = 0; i < sz; i++){
		sum += *p;
		p++;
	}// End for loop
	return sum;
}// End table_sum


// Function to get the average of an array
int table_avg(int *p, int sz){
	int avg, total = 0, cnt = 0;
	for (int i = 0; i < sz; i++){
		total += *p;
		p++;
		cnt++;
	}// End for loop
	avg = total / cnt;
	return avg;
}// End table_avg


// Function to find a value and return the location
int * table_contain(int *p, int sz, int v){
	for (int i = 0; i < sz; i++){
		if (*p == v){
			return p;
		}// End if
		else{
			return NULL;
		}// End else
		p++;
	}// End for loop
}// End table_contain


// Main
int main()
{
    const int Max = 20;
    int *ary, *bry;
    ary = new int[Max];//............  replace these two statements with dynamically allocated arrays.
    bry = new int[Max];
    int *p, *s, *tp;
    int avgValue, cnt;

    p = ary;//............   change &ary[0] to above used stements.
    s = bry;//............   change &bry[0] to above used stements.

    table_fill( p, Max, 10 );
    cout << endl << "Fill array with 10 " << endl;
    table_print( p, Max );  cout << endl << endl;


    cout << endl << "Add 1 to first 10 elements " << endl;
    table_add1( p, 10);
    table_print( p, Max );  cout << endl << endl;

    tp = s;   // save pointer
    for (int i=1; i<= Max; i++ )
    {
	table_fill( s, 1, i );
	s++;
    }
    cout << endl << "Fill array with 1 to 20 " << endl;
    s = tp;   // restore pointer
    table_print( s, Max );  cout << endl << endl;

    cout << endl << "Print reverse order " << endl;
    table_print_rev( s, Max );  cout << endl << endl;

    table_fill( p, Max, 0 );
    cout << endl << "Zero out array " << endl;
    table_print( p, Max );  cout << endl << endl;

    s = p;        // What's happening here?
    for (int i=Max; i>=0; i--)
    {
	table_add1( p, i );
	p++;
    }
    p = s;  //restore p and s
    s = tp;
    cout << endl << "Fill array with ???? " << endl;
    table_print( p, Max );  cout << endl << endl;

    cout << endl << "Print reverse order " << endl;
    table_print_rev( p, Max );  cout << endl << endl;

    cout << endl << "Copy p to s and print p and s" << endl;
    table_copy( s, p, Max);
    table_print( p, Max );  cout << endl << endl;
    table_print( s, Max );  cout << endl << endl;

    for (int i=0; i<Max/2+1; i++)
    {
	    s = p+10+i;
	    table_fill( s, 1, i*2 );
	    s = p+10-i;
	    table_fill( s, 1, i*3 );
    }
    s = tp;
    cout << endl << "Fill array with <-> " << endl;
    table_print( s, Max );  cout << endl << endl;

    cout << endl << "Min for previous table " << table_min( s, 15 );
    cout << endl << "Max for previous table " << table_max( s+10, 9);
    cout << endl << "Sum for previous table " << table_sum( s+5, 12);
    cout << endl << "Average for previous table " << table_avg( s+5, 12) << "\n";

    avgValue = table_avg( s, Max);

    for ( int i=1; i<=Max; i++)
    {
        if ( table_contain( s, Max, avgValue) )
        {
            cnt++;
        }
        s++;
    };
    cout << "How many array values are equal to the average?" << endl;
    cout << "         cnt = " << cnt << endl << endl;

    //..........  You add code here for the two other tasks I have in the specs
    s = tp; // reset s

    cout << "New Table:\n";
    table_print(s, Max); cout << "\n\n";
    int AVG = table_avg(s, Max);
    int count = 0;

    for (int i = 0; i < Max; i++){
    	if (*s < AVG){
    		count++;
    	}// End if
    	s++;
    }// End for loop

    cout << "There are " << count << " values that are less than the average of " << AVG << ".\n";

    int *NAry;
    NAry = s;

    //80 85 90 94 87 92 90 83 85 87 83
    	table_fill(NAry, 1, 80);
    	table_fill(NAry+1, 1, 85);
    	table_fill(NAry+2, 1, 90);
    	table_fill(NAry+3, 1, 94);
    	table_fill(NAry+4, 1, 87);
    	table_fill(NAry+5, 1, 87);
    	table_fill(NAry+6, 1, 92);
    	table_fill(NAry+7, 1, 90);
    	table_fill(NAry+8, 1, 83);
    	table_fill(NAry+9, 1, 83);
    	table_fill(NAry+10, 1, 85);
    	table_fill(NAry+11, 1, 87);
    	table_fill(NAry+12, 1, 83);
    	table_fill(NAry+13, 1, 83);
    	table_fill(NAry+14, 1, 83);

    	cout << "\nLoad grades into an array:\n";
    	table_print(NAry, 15);

    	int AV = table_avg(NAry, 15);
    	cout << "\n\nThe average is: " << AV;

    return 0;
}

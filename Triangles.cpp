/*
 * Triangles.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: William Ryan Clark
 */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int DiamondRight(int, int);
int DiamondLeft(int, int, int);
int MakeDiamond(int, int, int);
int TriangleRight(int, int);
int TriangleLeft(int, int, int);
int MakeTop(int, int, int);
int MakeBottom(int, int, int);
int h = 6; // row height


// DiamondRight function
int DiamondRight(int c, int j){

	if (j == 0){
		return 1;
	}// End if
	else{
		DiamondRight(c+1, j-1);
		cout << char(c) << " ";
		return 1;
	}// End else

}// End DiamondRight function


// DiamondLeft function
int DiamondLeft(int c, int j, int i){

	if(i==0 ){
		return 1;
	}// End if
	else if (i < j){
		cout << char(c) << " ";
		c = c + 1;
	}// End else if
	else{
		cout << "  ";
	}// End else
return DiamondLeft(c, j, i - 1);

}// End DiamondLeft function


// MakeDiamond function
int MakeDiamond(int c, int j, int i){

	if(i == 0){
		return 1;
	}// End if
	else{
		cout << endl;
		DiamondLeft(c, j, h);
		DiamondRight(c, j);
		MakeDiamond(c, j + 1, i - 1);
		cout << endl;
		DiamondLeft(c, j, h);
		DiamondRight(c, j);
		return 1;
	}// End else

}// End MakeDiamond


// TriangleRight function
int TriangleRight(int c, int j){

	if (j == 0){
		return 1;
	}// End if
	else{
		TriangleRight(c+1, j-1);
		cout << char(c) << " ";
		return 1;
	}// End else

}// End DiamondRight function


// TriangleLeft function
int TriangleLeft(int c, int j, int i){

	if(i == 0){
		return 1;
	}// End if
	else if (i < j){
		cout << char(c) << " ";
		c = c + 1;
	}// End else if
	else{
		cout << "  ";
	}// End else
return TriangleLeft(c, j, i - 1);

}// End DiamondLeft function


// MakeTop function
int MakeTop(int c, int j, int i){

	if(i == 0){
		return 1;
	}// End if
	else{
		MakeTop(c, j + 1, i - 1);
		cout << endl;
		TriangleLeft(c, j, h);
		TriangleRight(c, j);
		return 1;
	}// End else

}// End MakeDiamond


// MakeBottom function
int MakeBottom(int c, int j, int i){
	if(i == 0){
		return 1;
	}// End if
	else{
		TriangleLeft(c, j, h);
		TriangleRight(c, j);
		cout << endl;
		MakeBottom(c, j + 1, i - 1);
		return 1;
	}// End else
}// End MakeDiamond


// Main
int main(){

	char p ='A';// input starting character

     MakeDiamond(int(p), 0, h);
     cout << "\n\n";

     MakeTop(int(p), 0, h);

     MakeBottom(int(p), 0, h);
     return 0;
}// End main




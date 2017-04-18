/*
 * QuickSort.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: William Ryan Clark
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

// function to divide the array and returns the middle subscript
int splits(int ary[], int L, int R){
    int a = ary[L];
    int l = L - 1;
    int r = R + 1;
    int temp;

    while (l < r){
    	do{
    		r--;
    	}while (a < ary[r]);

        do{
        	l++;
        }while (a > ary[l]);

        if (l < r){
        	temp = ary[l];
            ary[l] = ary[r];
            ary[r] = temp;
       }// End if

    }// End while loop
    return r;           // returns middle subscript
}// End splits function


// Function to perform a quicksort on an integer array
void QS(int ary[], int lIndex, int rIndex){
        int mid;

        if (lIndex >= rIndex){
        	return;
        }// end if

        mid = splits(ary, lIndex, rIndex);
        QS(ary, lIndex, mid);
        QS(ary, mid + 1, rIndex);

}// End QS function


  //Interpolation Search
  int interpolation_search (int ar[], int value, int size)
  {
    int low = 0;
    int high = size - 1;
    int mid;

    while (ar[low] <= value && ar[high] >= value)
    {
      mid = low + ((value - ar[low]) * (high - low)) / (ar[high] - ar[low]);
      if (ar[mid] < value)
      {
        low = mid + 1;
      }
      else if (ar[mid] > value)
      {
        low = mid - 1;
      }
      else
      {
        return mid;
      }
    }

    if (ar[low] == value)
    {
      return low;
    }
    else
    {
      return -1;
    }
  }


// Main program
int main(){
        const int CAP = 15000;
        int ARY[CAP], inVal;
        // Seed the randomizer
        srand(time(0));

        //Load the ARRAY
        for (int i = 0; i < CAP; i++){
                ARY[i] = rand() % 15000;
        }// End for loop

        //print first twenty....before
        for (int c = 0; c < 20; c++){
        	cout << ARY[c] << " ";
        }// End for loop

        QS(ARY, 0, CAP);// Do the quicksort

        cout << "\n\n";

        //print first twenty....after
        for (int c = 0; c < 20; c++){
        	cout << ARY[c] << " ";
        }// End for loop


        cout << "Enter a value to search for:\n";
        cin >> inVal;

        int element = interpolation_search(ARY, inVal, CAP);

        if (element != -1){
        	cout << "Value was found in element " << element + 1 << "\n";
        }// end if
        else{
        	cout << "Value was not found\n";
        }// End else
        return 0;
}// End main

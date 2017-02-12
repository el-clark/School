/*
 * LinkList.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: William Ryan Clark
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

//Struct for linked list
struct LL{
	string name;
	int grade;
	LL *NLink;
	LL *GLink;
	LL *ALink;
};// End struct for link list


typedef	LL *node;
node names;
node grades;
node Agrades;


// Function prototypes
node NEWNODE();
void INSERT_N(string, int, int);
void LINK_G(node&);
void LINK_A(node&);
void PRINT_NAME(node&);
void PRINT_GRADE(node&);
void PRINT_AGRADE(node&);


// Function to create an empty node
node NEWNODE(){
	node temp;
     temp = new LL();
     temp->name = "";
     temp->grade = 0;
     temp->GLink = NULL;
     temp->NLink = NULL;
     temp->ALink = NULL;
     return temp;
}// End NEWNODE function


// Function to enter names and grades into the the list
void INSERT_N( string NM, int GD, int T){
	node c, p, temp;
	int PGrade = (double(GD) / double(T)) * 100;


		c = names ;
		p = NULL;

		while (c != NULL && c->name <= NM){
	    	p = c;
	    	c = c->NLink;
	    }// End while loop

	    	if (p != NULL){
	    			temp = NEWNODE();
	    			temp->name = NM;
	    			temp->grade = PGrade;
	    			p->NLink = temp;
	    			temp->NLink = c;
	    	}// End if
	        else {
	        		temp = NEWNODE();
	        		temp->name = NM;
	        		temp->grade = PGrade;
	        		temp->NLink = c;
	        		names = temp;
	        }// End else

	    	LINK_G(temp);// Build a link ordered by grades
	    	LINK_A(temp);// Build a link of students who made grades
}// End INSERT_N function


// Function to link grades together in descending order
void LINK_G(node &current){
	node c, p;
	c = grades;
	p = NULL;

	while (c != NULL){
		p = c;
		c = c->GLink;

		// create new head node if value is greater than the current head node
		if (current->grade > grades->grade){
			current->GLink = grades;
			grades = current;
			break;
		}// End if

		// If the next node is not null then insert in between else insert at the end
		if (c != NULL){
			if (current->grade <= p->grade && current->grade > c->grade){
				p->GLink = current;
				current->GLink = c;
				break;
			}// end if
		}//End if
		else{
			p->GLink = current;
			current->GLink = c;
		}// End if
	}// End while loop
}// End LINK_G function


// Function to link nodes of students who made A's
void LINK_A(node &current){

	// Check for NULL to create the head node
	if (Agrades == NULL){
		if (current->grade >= 90){
			Agrades = current;
		}// End if
	}// End if

	node c, p;
	c = Agrades ;
	p = NULL;

	if (current->grade >= 90){
		while (c != NULL && c->name <= current->name){
			p = c;
			c = c->ALink;
		}// End while loop

		if (p != NULL){
			p->ALink = current;
			current->ALink = c;
		}// End if
		else {
			current->ALink = c;
			Agrades = current;
		}// End else
	}// End if
}// End LINK_A function


// Function to print the link list
void PRINT_NAME(node &head){
	node c;
    c = head;

    while (c){
    	cout << setw(12) << c->name << "     " << c->grade << "\n";
    	c = c->NLink;
    }// End while
}// End PRINT_NAME function


// Function to print the link list
void PRINT_GRADE(node &head){
	node c;
    c = head;

    while (c){
    	cout << setw(12) << c->name << "     " << c->grade << "\n";
    	c = c->GLink;
    }// End while
}// End PRINT_GRADE function


// Function to print the link list
void PRINT_AGRADE(node &head){
	node c;
    c = head;

    while (c){
    	cout << setw(12) << c->name << "     " << c->grade << "\n";
    	c = c->ALink;
    }// End while
}// End PRINT_AGRADE function


// Main
int main(){
	// Input file
	string inPath = "/home/ryan/pgm_input/LinkLnamesAndGrades.txt";
	ifstream inFile (inPath.c_str());
	istringstream ss;

	// Variables
	string line, name;
	int grade, total = 0;

	// Get the first line with the total points value
	getline(inFile, line);
	ss.str(line);
	ss >> total;

	// Get the next line to crate the first node
	getline(inFile, line);
	ss.str(line);
	ss >> name >> grade;

	// Create the first node
	names = NEWNODE();
	names->name = name;
	names->grade = (double(grade) / double(total)) * 100;

	grades = &*names;// set a starting point for grades;

	LINK_A(names);// check to see if first node is an A and start building the links

	// Get everything else and load into the linked list
	while(getline(inFile, line)){

		ss.str(line);
		ss >> name >> grade;

		INSERT_N(name, grade, total);// Insert data into list sorted by name

	}// End while loop
	cout << "Sorted by Names:\n\n";
	PRINT_NAME(names);// Print list sorted by name
	cout << "\nSorted by Grades (Descending):\n\n";
	PRINT_GRADE(grades);// Print list sorted by grades
	cout << "\nExempt List ordered by name:\n\n";
	PRINT_AGRADE(Agrades);
}// End main

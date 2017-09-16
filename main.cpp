// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   main.cpp
   AUTHOR: Sean Widmier
   DATE:   August 29, 2017
   COURSE: CS221-02, FALL 2017
  
   Description:
    Main file for Program #1. This program uses a basic student class to construct a student object, which will then accept both homework and test grades, as well as weights, in order to calculate the total average. All of the data will be displayed at the end.
*/
//***************************************************************************//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Student.h"

//#define DEBUG_RESET

using namespace std;

int main(void){
    string first_name, last_name; //String variables used to store the first and last names that we get from the user.

    Student s;
    
#ifdef DEBUG_RESET
    for(int i = 0; i < 2; i++){
#endif
    cout << "This is a basic grade calculator for one student object. Please prepare the student's name, test and homework grades (10 max), and the weights used for grade averaging." << endl << endl;
    cout << "Please enter a student's first name: ";
    cin >> first_name;
    
    cout << "Please enter a student's last name: ";
    cin >> last_name;
    
    s.setName(first_name,last_name); //Once we have received the input, we can send the first and last names to be stored using the setName function
    
    cout << "TESTS" << endl;
    for(int i = 0; i < MAXGRADES; i++){ //This for loop will prompt the user to input the 10 test grades, or manually stop it themselves.
        float grade;
        cout << "Please enter test grade " << i+1 << ", enter a -1 to stop." << endl;
        cin >> grade;
        
        if(grade < 0)
            break;
        
        s.addTest(grade);
    }
    
    cout << "HOMEWORK" << endl;
    for(int i = 0; i < MAXGRADES; i++){
        float grade;
        cout << "Please enter homework grade " << i+1 << ", enter a -1 to stop." << endl;
        cin >> grade;
        
        if(grade < 0)
            break;
        s.addHW(grade);
    }
    
    float weight; //Variable used to locally store the user inputted grade weight for tests, then homework.
    cout << "GRADE WEIGHTS" << endl;
    cout << "Please enter grade weight for tests as a number between 0 and 1: ";
    cin >> weight;
    s.weight_setTest(weight);
    
    cout << "Please enter grade weight for homework as a number between 0 and 1: ";
    cin >> weight;
    s.weight_setHW(weight);
    
    cout << endl << "FINAL GRADEBOOK:" << endl;
    s.print();
    cout << "Current number of tests: " << s.getNumTests() << " and homework grades: " << s.getNumHW() << endl;
    cout << endl << "Current average: " << s.getAverage() << endl;
    
    cout << "The program has completed. It will now exit." << endl;
#ifdef DEBUG_RESET
    s.reset();
    }
#endif
    return 0;
}
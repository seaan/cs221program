// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   main.cpp
   AUTHOR: Sean Widmier
   DATE:   September 14, 2017
   COURSE: CS221-02, FALL 2017
  
   Description:
    Main file for Program #2.
*/
//***************************************************************************//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream> //file stuff 

#include "Student.h"
#include "StudentList.h"

using namespace std;

int main(void){
    string first_name, last_name; //String variables used to store the first and last names that we get from the user.
    string path;
    StudentList list;
    
    ifstream infile;
    ofstream outfile;

    cout << "This is a basic grade calculator for multiple student objects. An input file will be used for data, and an output file shall be written to." << endl << endl;
    
    cout << "Please type an input file path: " << endl;
    cin >> path;
    infile.open(path.c_str());
    
    cout << "Please type an output file path: " << endl;
    cin >> path;
    outfile.open(path.c_str());
    
    while(!infile.eof() && !list.isFull()){
        Student s;
        s.read(infile);
        
        list.addStudent(s);
    }
    
    outfile << "FINAL GRADEBOOK for [" << list.getSize() << "] STUDENTS:" << endl;
    outfile << "OVERALL CLASS AVERAGE:" << list.getClassAverage() << endl << endl;

    list.print(outfile);
    
    cout << "The program has completed. It will now exit." << endl;
    return 0;
}
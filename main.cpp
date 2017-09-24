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
    string first_name, last_name;                   //String variables used to store the first and last names that we get from the user.
    string path;                                    //The user inputted path for the input and output files
    StudentList list;                               //A StudentList object to store the students from our input file in
    
    ifstream infile;                                //input file stream
    ofstream outfile;                               //output file stream

    cout << "This is a basic grade calculator for multiple student objects. An input file will be used for data, and an output file shall be written to." << endl << endl;
    
    cout << "Please type an input file path: " << endl;
    cin >> path;
    infile.open(path.c_str());                      //after prompting the user for the path, open the input file using that path
    
    cout << "Please type an output file path: " << endl;
    cin >> path;
    outfile.open(path.c_str());
    
    while(!infile.eof()){         //until we've reached the end of the file or the list is full
        Student s;                                  //we will want to have a new student object for every time this loop is complete, so we can add the next to our list
        s.read(infile);                             //this will read in the details for the student object s from the input file
        
        list.add(s);                         //after we've read in the details we can store the student in studentlist
    }
    
    outfile << "FINAL GRADEBOOK for [" << list.getSize() << "] STUDENTS:" << endl;          
    outfile << "OVERALL CLASS AVERAGE:" << list.getAverage() << endl << endl;

    list.print(outfile);                            //This will print each student object we created, listing the name, # of grades, and average
    
    cout << "The program has completed. It will now exit." << endl;
    return 0;
}
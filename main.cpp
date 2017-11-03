// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   main.cpp
   AUTHOR: Sean Widmier
   DATE:   November 7th, 2017
   COURSE: CS221-02, FALL 2017
  
   Description:
    Main file for Program #4.
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
#include "utilities.h"

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
    infile.open(path.c_str());                      //after prompting the user for the path, open the input file using that path*/
    if(!infile){
        cout << "Error opening path, ending program.";
        return 0;
    }
    
    cout << "Please type an output file path: " << endl;
    cin >> path;
    outfile.open(path.c_str());
    if (!outfile) {
        cout << "Error opening path, ending program.";
        return 0;
    }
    
    while(!infile.eof()){                           //until we've reached the end of the file or the list is full
        Student s;                                  //we will want to have a new student object for every time this loop is complete, so we can add the next to our list
        s.read(infile);                             //this will read in the details for the student object s from the input file
        
        list.add(s);                                //after we've read in the details we can store the student in studentlist
    }
    
    cout << "Gradebook created." << endl << endl;
    
    char answer = 'y';                              //input char for user to indicate what they want to do
    while(answer == 'y' || answer == 'Y'){          //while the user still wants to..
        
        cout << "Would you like to search for a student? Y/N" << endl;;
        cin >> answer;
        if(answer == 'y' || answer == 'Y') {        //if the user still wants to..
            cout << "Enter the name of the student: " << endl;
            cin >> first_name >> last_name;
            list.searchList(first_name, last_name); //search the list we made
        }
        
        cout << "Would you like to delete a student? Y/N" << endl;
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            cout << "Enter the name of the student: " << endl;
            cin >> first_name >> last_name;
            list.deleteStudent(first_name, last_name);
        }
        
        cout << "Would you like to continue? Y/N" << endl;
        cin >> answer;
    }
    
        
    outfile << "FINAL GRADEBOOK for [" << list.getSize() << "] STUDENTS:" << endl;          
    outfile << "OVERALL CLASS AVERAGE:" << list.getAverage() << endl << endl;
    
    cout << endl << "FINAL GRADEBOOK for [" << list.getSize() << "] STUDENTS:" << endl;          
    cout << "OVERALL CLASS AVERAGE:" << list.getAverage() << endl << endl;

    list.print(outfile);                            //This will print each student object we created, listing the name, # of grades, and average
    
    
    cout << endl << "The program has completed. It will now exit." << endl;
    return 0;
}
// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   main.cpp
   AUTHOR: Sean Widmier
   DATE:   November 2, 2017
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
#include "StudentTree.h"

using namespace std;

int main(void){
    string first_name, last_name;                   //String variables used to store the first and last names that we get from the user.
    string path;                                    //The user inputted path for the input and output files
    StudentTree tree;                               //A StudentList object to store the students from our input file in
    
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
    
    while(!infile.eof()){                           //until we've reached the end of the file or the list is full
        Student s;                                  //we will want to have a new student object for every time this loop is complete, so we can add the next to our list
        s.read(infile);                             //this will read in the details for the student object s from the input file
        
        tree.insert(s);                             //after we've read in the details we can store the student in studentlist
    }
    
    cout << "Gradebook created." << endl << endl;
    
    cout << "Number of students: " << tree.count() << endl;
    tree.display(cout, 1);                          //display objects in order
    
    char answer = 'y';                              //input char for user to indicate what they want to do
    while(answer == 'y' || answer == 'Y'){          //while the user still wants to..

       cout << "Would you like to input a student? Y/N" << endl;;
       cin >> answer;
       if(answer == 'y' || answer == 'Y') {        //if the user still wants to..
           Student s;
           s.readcin();
           
           tree.insert(s);
       }
   }
    
    tree.display(cout, 3);                            //print in descending order
    
    
    cout << endl << "The program has completed. It will now exit." << endl;
    return 0;
}
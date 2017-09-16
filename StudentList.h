// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   StudentList.h
   AUTHOR: Sean Widmier
   DATE:   September 10, 2017
   COURSE: CS221-02, FALL 2017s

   Class StudentList header file.  The methods for class StudentList are 
   declared here. See StudentList.cpp for implementation
*/
//***************************************************************************//

#include "Student.h"
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#define MAXSTUDENTS 25
using namespace std;
class StudentList {
    Student arr_students[MAXSTUDENTS];                                  //array to hold all of our student objects
    int student_count;                                                  //variable to keep track of the number of students we have

public:	
	// prototypes for public interface methods, definitions are all located in Student.cpp, along with descriptions.
    
        StudentList();                                                  //student constructor
        void addStudent(Student s);                                     //add a new student object to the list
        void print(ofstream &outfile);                                  //calls print for all student objects
        float getClassAverage(void);                                    //returns the class average
        void reset(void);                                               //resets each student object
        bool isFull(void);                                              //returns if the list is full
        int getSize(void);                                              //returns the size of the list
};

#endif /* STUDENTLIST_H */


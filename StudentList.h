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
#include "utilities.h"
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#define MAXSTUDENTS 25
using namespace std;

class Node {
public:
    Student item;
    Node *after;
    Node *before;
    Node(const Student &studIn){
        item = studIn;
        after = NULL;
        before = NULL;
    }
};

class StudentList {
    Node *first;
    Node *last;
    Node *current;
    
    int student_count;                                                  //variable to keep track of the number of students we have
public:	
    //Constructor and Destructor
    StudentList();                                                  //student constructor
    ~StudentList();

    //public member functions
    bool add(Student s);                                     //add a new student object to the list
    void print(ofstream &outfile);                           //calls print for all student objects
    float getAverage(void);                                  //returns the class average
    void clear(void);                                        //resets each student object
    bool isEmpty(void);
    int getSize(void);                                       //returns the size of the list
    bool searchList(string n_first, string n_last);
    bool deleteStudent(string n_first, string n_last);
};

#endif /* STUDENTLIST_H */


#include "StudentList.h"

// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   StudentList.cpp
   AUTHOR: Sean Widmier
   DATE:   September 10, 2017
   COURSE: CS221-02, FALL 2017

   Class StudentList implementation file.  The methods for class StudentList are 
   developed here. Please see StudentList.h for the declaration of StudentList.
*/
//***************************************************************************//

//-------------------------------------------------------------------
// StudentList Constructor:
// Constructor for the StudentList class, including parameters for creation.
//-------------------------------------------------------------------
StudentList::StudentList(){
    student_count = 0;
    first = NULL;
    current = NULL;
}

StudentList::~StudentList(){
    clear();
}

//-------------------------------------------------------------------
// addStudent:
// Adds a student object to our array of students.
//-------------------------------------------------------------------
bool StudentList::add(Student s){
    Node *pNew;
    pNew = new Node(s);
    if(!pNew){
        cout << "Error in dynamic allocation!" << endl;
        return false;
    }
    
    if(isEmpty())
        first = pNew;
    else
        last->next = pNew;
    
    last = pNew;
    student_count++;
    return true;
}

//-------------------------------------------------------------------
// print:
// Iterates through each student object and calls their print function.
//-------------------------------------------------------------------
void StudentList::print(ofstream &outfile){
    Node *p = first;
    while(p){
        p->item.print(outfile);
        p = p->next;
    }
}

//-------------------------------------------------------------------
// Student Constructor:
// Constructor for the Student class, including parameters for creation.
//-------------------------------------------------------------------
float StudentList::getAverage(void){
    float average = 0;
    Node *p = first;
    while(p){
        average += p->item.getAverage();
        p = p->next;
    }
    
    average /= student_count;                //find the average
    
    return average;
}

//-------------------------------------------------------------------
// reset:
// Iterates through all of the student objects and resets each one.
//-------------------------------------------------------------------
void StudentList::clear(void){
    Node *p, *q;
    p = first;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    first = NULL;
    last = NULL;
}


bool StudentList::isEmpty(void){
    if(!(first && last))
        return true;
    else
        return false;
}


//-------------------------------------------------------------------
// getSize:
// Returns class size.
//-------------------------------------------------------------------
int StudentList::getSize(void){
    return student_count;
}


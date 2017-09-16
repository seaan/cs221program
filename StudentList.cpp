
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
    reset();                                //Calls a reset on all of the student objects to make sure everything is zero.
}

//-------------------------------------------------------------------
// addStudent:
// Adds a student object to our array of students.
//-------------------------------------------------------------------
void StudentList::addStudent(Student s){
    if(student_count == MAXSTUDENTS){
        cout << "Error! Max number of students reached!" << endl;
        return;
    }
        
    students[student_count++] = s;          //Add a new student, as well as iterate the count by 1.
}

//-------------------------------------------------------------------
// print:
// Iterates through each student object and calls their print function.
//-------------------------------------------------------------------
void StudentList::print(ofstream &outfile){
    for(int i = 0; i < student_count; i++){
        students[i].print(outfile);         //This loop will iterate through every student object that we have created and call it's print function.
    }
}

//-------------------------------------------------------------------
// Student Constructor:
// Constructor for the Student class, including parameters for creation.
//-------------------------------------------------------------------
float StudentList::getClassAverage(void){
    float average = 0;
    for(int i = 0; i < student_count; i++){
        average += students[i].getAverage(); //add upp all of the individual averages for each student
    }
    
    average /= student_count;                //find the average
    
    return average;
}

//-------------------------------------------------------------------
// reset:
// Iterates through all of the student objects and resets each one.
//-------------------------------------------------------------------
void StudentList::reset(void){
    for(int i = 0; i < MAXSTUDENTS; i++){
        students[i].reset();                //will reset every student object
    }
}

//-------------------------------------------------------------------
// isFull:
// Checks to see if our list is full.
//-------------------------------------------------------------------
bool StudentList::isFull(void){
    if(student_count >= MAXSTUDENTS)
        return true;
    return false;
}

//-------------------------------------------------------------------
// getSize:
// Returns class size.
//-------------------------------------------------------------------
int StudentList::getSize(void){
    return student_count;
}


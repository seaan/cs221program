// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   Student.h
   AUTHOR: Sean Widmier
   DATE:   August 28, 2017
   COURSE: CS221-02, FALL 2017

   Class Student definition file.  
*/
//***************************************************************************//
#pragma once
#include <string>
#include <iostream>

//#define DEBUG_AVG
//#define DEBUG_ADDTEST
//#define DEBUG_ADDHW


#define MAXGRADES 10                                              //Currently all grade arrays have a max of 10 members.
using namespace std;

class Student {
    string firstName;                                         // student's first name
    string lastName;                                          // student's last name

    float testgrades[MAXGRADES];                              //test grade array
    int testcount;                                            //number of test grades, also used to iterate through the test_grade array
    float testweight;                                         //the grade weight for tests, used when computing average

    float hwgrades[MAXGRADES];                                //homework grade array
    int hwcount;                                              //number of homework grades, also used to iterate through the hw_grade array
    float hwweight;                                           //the grade weight for homework, used when computing average

    float average;                                            //student's average
        
public:	
    
    Student();                                                //student constructor
    void setName(string, string);                             //sets a name for the current student object

    string getFirstName(void);                                //returns the first name of the student object
    string getLastName(void);                                 //returns the last name

    void print(void);
    void filePrint(ofstream &outfile);                            //prints out a grade report for an individual student, including last name, first name, number of tests, and grade average

    void addTest(float);                                      //adds a test grade to the student object's grades
    void addHW(float);                                        //adds a homework grade

    void weight_setTest(float);                               //sets the weight of the test grades
    void weight_setHW(float);                                 //sets the weight of the homework grades

    void computeAverage(void);                                //computes the overall average for the current student
    float getAverage(void);                                   //prompts for a computation, then returns the average for the current student

    void reset(void);                                         //completely resets the student object, returning every value back to default

    int getNumTests(void);                                    //returns the number of test grades
    int getNumHW(void);                                       //returns the number of homework grades

    void removeTest(void);                                    //removes a test grade
    void removeHW(void);                                      //removes a homework grade

    void read(ifstream &infile);                              //reads in the information for a student object from an input file stream
    void readcin(void);

    bool operator==(Student s);
    bool operator>(Student s);
    bool operator<(Student s);
    
};
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


#define MAXGRADES 10                                                      //Currently all grade arrays have a max of 10 members.
using namespace std;
class Student {
	string m_firstName;                                         // student's first name
	string m_lastName;                                          // student's last name
        
        float m_testgrades[MAXGRADES];                              //test grade array
        int m_testcount;                                            //number of test grades, also used to iterate through the test_grade array
        float m_testweight;                                         //the grade weight for tests, used when computing average
        
        float m_hwgrades[MAXGRADES];                                //homework grade array
        int m_hwcount;                                              //number of homework grades, also used to iterate through the hw_grade array
        float m_hwweight;                                           //the grade weight for homework, used when computing average
        
        float m_average;                                            //student's average
        
public:	
	// prototypes for public interface methods, definitions are all located in Student.cpp, along with descriptions.
    
        Student();                                                  //student constructor
	void setName(string, string);        
        
	string getFirstName(void);
        string getLastName(void);
        
        void print(ofstream &outfile);
        
        void addTest(float);
        void addHW(float);
        
        void weight_setTest(float);
        void weight_setHW(float);
        
        void computeAverage(void);
        float getAverage(void);
        
        void reset(void);
        
        int getNumTests(void);
        int getNumHW(void);

        void removeTest(void);
        void removeHW(void);
        
        void read(ifstream &infile);
        
};
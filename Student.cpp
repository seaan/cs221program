// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   Student.cpp
   AUTHOR: Sean Widmier
   DATE:   August 17, 2017
   COURSE: CS221-02, FALL 2017

   Class Student implementation file.  The methods for class Student are 
   developed here. Please see Student.h for the declaration of Student.
*/
//***************************************************************************//
#include "Student.h"

//-------------------------------------------------------------------
// setName:
// Supply this function with a first name and a last name (strings).
// The student's name is set to these values
//-------------------------------------------------------------------
void Student::setName(string fn, string ln) {
    m_firstName = fn;
    m_lastName = ln;
}

//-------------------------------------------------------------------
// getFirstName:
// Returns a copy of the student's first name to the caller
//-------------------------------------------------------------------
string Student::getFirstName() {
    return m_firstName;
}

//-------------------------------------------------------------------
// getLastName:
// Returns a copy of the student's last name to the caller
//-------------------------------------------------------------------
string Student::getLastName() {
    return m_lastName;
}

//-------------------------------------------------------------------
// print:
// Prints the student's data to the standard output stream, formatted
//-------------------------------------------------------------------
void Student::print(void) {
    cout << m_lastName << ", " << m_firstName << endl;
}

//-------------------------------------------------------------------
// addTest:
// Adds a test grade to the student's gradebook.
//-------------------------------------------------------------------
void Student::addTest(float grade) {
    if(m_testcount > 9){
        cout << "Error! Can't enter more than 10 test grades!";
        return;
    }
    while(grade > 100 || grade < 0){
        cout << "Error! Please enter a grade between 0 and 100!" << endl;
        cin >> grade;
    }
    m_testgrades[m_testcount++] = grade;
    
#ifdef DEBUG_ADDTEST
    cout << "Test added: " << grade << endl;
    cout << "Current test array: " << endl;
    for(int i = 0; i < m_testcount; i++)
        cout << m_testgrades[i] << endl;
#endif
}

//-------------------------------------------------------------------
// addHW:
// Adds a homework grade to the student's gradebook.
//-------------------------------------------------------------------
void Student::addHW(float grade) {
    if(m_hwcount > 9){
        cout << "Error! Can't enter more than 10 homework grades!";
        return;
    }
    while(grade > 100 || grade < 0){
        cout << "Error! Please enter a grade between 0 and 100!" << endl;
        cin >> grade;
    }
    m_hwgrades[m_hwcount++] = grade;
    
#ifdef DEBUG_ADDTEST
    cout << "HW added: " << grade << endl;
#endif
}

//-------------------------------------------------------------------
// weight_setTest:
// Sets the grade weight of tests used when calculating the average.
//-------------------------------------------------------------------
void Student::weight_setTest(float weight) {
    while(weight < 0 || weight > 1){
        cout << "Error! Please enter a number between 0 and 1!";
        cin >> weight;
    }
    m_testweight = weight;
}

//-------------------------------------------------------------------
// weight_setHW:
// Sets the grade weight of homework used when calculating the average.
//-------------------------------------------------------------------
void Student::weight_setHW(float weight) {
    while(weight < 0 || weight > 1){
        cout << "Error! Please enter a number between 0 and 1!";
        cin >> weight;
    }
    m_hwweight = weight;
}

//-------------------------------------------------------------------
// computeAverage:
// Computes the student's average and stores it.
//-------------------------------------------------------------------
void Student::computeAverage(void) {
    float test_avg = 0;                     //Variable to be used to calculate the test average for the student.
    float hw_avg = 0;                       //Variable to be used to calculate the homework average for the student.
    
    for(int i = 0; i < m_testcount; i++){   //This will add up all of the members of the test grades array.
        test_avg += m_testgrades[i];
    }
    
    for(int i = 0; i < m_hwcount; i++){
        hw_avg += m_hwgrades[i];
    }
#ifdef DEBUG_AVG
    cout << "test_avg: " << test_avg << " hw_avg: " << hw_avg << endl;
#endif
            
    test_avg /= m_testcount;              //This will take the average of all of the test grades by dividing our sum by the number of test grades.
    hw_avg /= m_hwcount;
    
#ifdef DEBUG_AVG
    cout << "test_avg: " << test_avg << " hw_avg: " << hw_avg << endl;
#endif
    
    m_average = test_avg * m_testweight + hw_avg * m_hwweight; //The total average can be calculated using (test average * test weight) + (homework average * homework weight)
}

//-------------------------------------------------------------------
// getAverage:
// Returns a copy of the student's average to the caller
//-------------------------------------------------------------------
float Student::getAverage(void) {
    computeAverage();
    return m_average;
}

//-------------------------------------------------------------------
// reset:
// Completely resets the object's grade and weight inputs.
//-------------------------------------------------------------------
void Student::reset(void)  {
    for(int i = m_testcount; i > 0; i--)
        m_testgrades[i] = 0;
    
    for(int i = m_hwcount; i > 0; i--)
        m_hwgrades[i] = 0;
    
    m_testcount = 0;
    m_hwcount = 0;
    m_testweight = 0.50;
    m_hwweight = 0.50;
    
    cout << "Grades successfully reset." << endl;
}

//-------------------------------------------------------------------
// getNumHW:
// Returns the current number of test grades.
//-------------------------------------------------------------------
int Student::getNumTests(void)  {
    return m_testcount;
}

//-------------------------------------------------------------------
// getNumHW:
// Returns the current number of HW grades.
//-------------------------------------------------------------------
int Student::getNumHW(void)  {
    return m_hwcount;
}
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
#include "utilities.h"
#include <sstream>

//-------------------------------------------------------------------
// Student Constructor:
// Constructor for the Student class, including parameters for creation.
//-------------------------------------------------------------------
Student::Student(){
    string firstName = "unknown";					  // student's first name
    string lastName = "unknown";					  // student's last name

    float testgrades[MAXGRADES];                                    //test grade array
    int testcount = 0;                                              //number of test grades, also used to iterate through the test_grade array
    float testweight = .50;                                         //the grade weight for tests, used when computing average

    float hwgrades[MAXGRADES];                                      //homework grade array
    int hwcount = 0;                                                //number of homework grades, also used to iterate through the hw_grade array
    float hwweight = .50;                                           //the grade weight for homework, used when computing average

    float average = 0;                                                  //student's average
    
    reset();
}
//-------------------------------------------------------------------
// setName:
// Supply this function with a first name and a last name (strings).
// The student's name is set to these values
//-------------------------------------------------------------------
void Student::setName(string fn, string ln) {
    firstName = fn;
    lastName = ln;
}

//-------------------------------------------------------------------
// getFirstName:
// Returns a copy of the student's first name to the caller
//-------------------------------------------------------------------
string Student::getFirstName() {
    return firstName;
}

//-------------------------------------------------------------------
// getLastName:
// Returns a copy of the student's last name to the caller
//-------------------------------------------------------------------
string Student::getLastName() {
    return lastName;
}

//-------------------------------------------------------------------
// print:
// Prints the student's data to the standard output stream, formatted
//-------------------------------------------------------------------
void Student::print(void) {
    computeAverage();
    cout << lastName << ", " << firstName << endl;
    cout << "Number of Grades: " << testcount << " tests, " << hwcount << " homeworks." << endl;
    cout << "Average: " << average << endl << endl;
}

//-------------------------------------------------------------------
// print:
// Prints the student's data to the standard output stream, formatted
//-------------------------------------------------------------------
void Student::filePrint(ofstream &outfile) {
    computeAverage();
    outfile << lastName << ", " << firstName << endl;
    outfile << "Number of Grades: " << testcount << " tests, " << hwcount << " homeworks." << endl;
    outfile << "Average: " << average << endl << endl;
}

//-------------------------------------------------------------------
// addTest:
// Adds a test grade to the student's gradebook.
//-------------------------------------------------------------------
void Student::addTest(float grade) {
    if(testcount > 9){
        cout << "Error! Can't enter more than 10 test grades!";
        return;
    }
    while(grade > 100 || grade < 0){
        cout << "Error! Please enter a grade between 0 and 100!" << endl;
        cin >> grade;
    }
    testgrades[testcount++] = grade;
}

//-------------------------------------------------------------------
// addHW:
// Adds a homework grade to the student's gradebook.
//-------------------------------------------------------------------
void Student::addHW(float grade) {
    if(hwcount > 9){
        cout << "Error! Can't enter more than 10 homework grades!";
        return;
    }
    while(grade > 100 || grade < 0){
        cout << "Error! Please enter a grade between 0 and 100!" << endl;
        cin >> grade;
    }
    hwgrades[hwcount++] = grade;
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
    testweight = weight;
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
    hwweight = weight;
}

//-------------------------------------------------------------------
// computeAverage:
// Computes the student's average and stores it.
//-------------------------------------------------------------------
void Student::computeAverage(void) {
    float test_avg = 0;                     //Variable to be used to calculate the test average for the student.
    float hw_avg = 0;                       //Variable to be used to calculate the homework average for the student.
    
    for(int i = 0; i < testcount; i++){   //This will add up all of the members of the test grades array.
        test_avg += testgrades[i];
    }
    
    for(int i = 0; i < hwcount; i++){
        hw_avg += hwgrades[i];
    }
            
    test_avg /= testcount;              //This will take the average of all of the test grades by dividing our sum by the number of test grades.
    hw_avg /= hwcount;
    
    average = test_avg * testweight + hw_avg * hwweight; //The total average can be calculated using (test average * test weight) + (homework average * homework weight)
}

//-------------------------------------------------------------------
// getAverage:
// Returns a copy of the student's average to the caller
//-------------------------------------------------------------------
float Student::getAverage(void) {
    computeAverage();
    return average;
}

//-------------------------------------------------------------------
// reset:
// Completely resets the object's grade and weight inputs.
//-------------------------------------------------------------------
void Student::reset(void)  {
    for(int i = MAXGRADES; i > 0; i--)
        testgrades[i] = 0;
    
    for(int i = MAXGRADES; i > 0; i--)
        hwgrades[i] = 0;
    
    testcount = 0;
    hwcount = 0;
    testweight = 0.50;
    hwweight = 0.50;
}

//-------------------------------------------------------------------
// getNumHW:
// Returns the current number of test grades.
//-------------------------------------------------------------------
int Student::getNumTests(void)  {
    return testcount;
}

//-------------------------------------------------------------------
// getNumHW:
// Returns the current number of HW grades.
//-------------------------------------------------------------------
int Student::getNumHW(void)  {
    return hwcount;
}

//-------------------------------------------------------------------
// removeTest:
// Removes the most recent test.
//-------------------------------------------------------------------
void Student::removeTest(void)  {
    testgrades[testcount] == 0;
    testcount--;
}

//-------------------------------------------------------------------
// removeHW:
// Removes the most recent homework.
//-------------------------------------------------------------------
void Student::removeHW(void)  {
    testgrades[hwcount] == 0;
    hwcount--;
}

//-------------------------------------------------------------------
// read:
// Allows the student object to read input from a data stream.
//-------------------------------------------------------------------
void Student::read(ifstream &infile){
    string fname, lname, input;             //Variables to read in the first and last name, as well as whatever input we want.
    float grade;                            //Stores the most recent grade read
    char next_char;                         //Used to throw away useless characters in the input file
            
    clearLeadingWhitespace(infile);         //First clear the leading whitespace

    infile >> fname;
    infile >> lname; 
    setName(fname, lname);                  //Get the first and last name for the student, then input them into the object

    infile.get(next_char);

    clearLeadingWhitespace(infile);
    getline(infile, input);                 //Get the next line to be input as test grades.
    istringstream test_line(input);         //Create a string stream so that we can easily input each grade.
    
    while(!test_line.eof()){                //Until we reach the end of the string stream.
        test_line >> grade;                 
        addTest(grade);                     //Grab the next grade from the string stream and input it.
    }
    
    removeTest();                           //We will need to remove the duplicate grade at the end (bug with using stringstream).

    clearLeadingWhitespace(infile);         //We can then do the exact same thing for the next line, which would be homeworks.
    getline(infile, input);
    istringstream hw_line(input);
    while(!hw_line.eof()) {
        hw_line >> grade;
        addHW(grade);
    }
    
    if(!infile.eof())                       //The last grade will not duplicate if it is at the end of the file.
        removeHW();
}

bool Student::operator==(Student s){
    if(lastName == s.lastName && firstName == s.firstName)
        return true;
    return false;
}

bool Student::operator>(Student s){
    if(lastName > s.lastName)
        return true;
    else if(lastName == s.lastName){
        if(firstName > s.firstName)
            return true;
        
        return false;
    }
    else
        return false;
}

bool Student::operator<(Student s){
    if(lastName < s.lastName)
        return true;
    else if(lastName == s.lastName){
        if(firstName < s.firstName)
            return true;
        
        return false;
    }
    else
        return false;
}



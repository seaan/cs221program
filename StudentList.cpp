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
}

//-------------------------------------------------------------------
// StudentList Destructor:
// Uses clear() to delete every node in the list.
//-------------------------------------------------------------------
StudentList::~StudentList(){
    clear();
}

//-------------------------------------------------------------------
// add:
// Adds a node to the linked list using the provided student info.
//-------------------------------------------------------------------
bool StudentList::add(Student s){
    Node *pNew;                                         //new node to hold the inputted student information.
    Node *q;                                            //node used for searching and indexing
    pNew = new Node(s);                                 //allocate the new node
    if(!pNew){
        cout << "Error in dynamic allocation!" << endl;
        return false;
    }
    
    if(isEmpty()){                                      //if this is the first node, just put it in             
        first = pNew;
        last = pNew;
    }
    else{
        q = first;
        while(q && q->item < pNew->item)                //if not, we'll need to find where to put it
            q = q->after;                               //keep going if we're still below where we need to be
        
        /* Reached the end of the list */
        if(!q){
            pNew->before = last;
            last->after = pNew;                         //need to move up our previously last node and put pnew after it
            pNew->after = NULL;
            last = pNew;
        }

        /* Reached the front or the middle */
        else{
            pNew->before = q->before;
            if(!pNew->before)
                first = pNew;                           //if we're at the front, we'll need to reassign first
            else
                q->before->after = pNew;                //if not, the node before us needs to know we're here  

            pNew->after = q;                            //q is evaluated after it's changed in the while, so it will be after pnew
            q->before = pNew;
        }
    }
    student_count++;
    return true;
}

//-------------------------------------------------------------------
// print:
// Iterates through each node and calls their print function.
//-------------------------------------------------------------------
void StudentList::print(ofstream &outfile){
    Node *p = first;                                 //p will be our index node
    while(p){
        p->item.filePrint(outfile);
        p = p->after;
    }
}

//-------------------------------------------------------------------
// getAverage:
// Computes the average of the entire class.
//-------------------------------------------------------------------
float StudentList::getAverage(void){
    float average = 0;
    Node *p = first;
    while(p){
        average += p->item.getAverage();            //get each student's average
        p = p->after;
    }
    
    average /= student_count;                       //find the total average
    
    return average;
}

//-------------------------------------------------------------------
// clear:
// Iterates through all of the nodes and deletes each one.
//-------------------------------------------------------------------
void StudentList::clear(void){
    Node *p, *q;                                    //p is the node to delete, q is the index
    p = first;
    while(p){
        q = p->after;
        delete p;
        p = q;
    }
    first = NULL;                                   //should reset our first and last variables before we're done
    last = NULL;
}

//-------------------------------------------------------------------
// isEmpty:
// Checks if the list is empty.
//-------------------------------------------------------------------
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

//-------------------------------------------------------------------
// searchList:
// Searches for the appropriate student, if the student isn't found return the two nearest.
//-------------------------------------------------------------------
bool StudentList::searchList(string n_first, string n_last){
    Node *q;                                        //index node
    Student s;                                      //a student object to be used to compare our input to the item that we're indexed at
    
    q = first;
    
    n_first = allCaps(n_first);                     //need to make sure the cases match
    n_last = allCaps(n_last);
    s.setName(n_first,n_last);                      //we can fill in the inputted name as the name of the student object, so we can use the overloaded operators
    
    while(q && !(q->item == s) && (q->item < s))    //until we're at the end of the list, or we're at the index of the thing we're searching for, or we're past where the index should be
        q = q->after;
    
    if(!q && student_count > 1){
        cout << "Student not found, printing two nearest: " << endl << endl;
        last->item.print();                         //if our input is past the end of our current list, the two nearest are the first and last indexes
        first->item.print();
    }
    else if (!q) {
        cout << "Student not found, printing nearest: " << endl << endl;
        if(q->after)
            q->after->item.print();
        else if(q->before)
            q->before->item.print();
        else
            cout << "No students found." << endl;
    }
    else if(q->item == s){                          //if our input is actually in the list
        cout << "Student found: " << endl;
        q->item.print();                            //just print the info
    }
    else if (q->item > s) {                         //if we've passed where we think the index should be (since the list is sorted)
        cout << "Student not found, printing two nearest: " << endl << endl;
        
        if(q->before)
            q->before->item.print();                //if we're not at the first index, we can actually print the item before
        else
            last->item.print();                     //if we're at the beginning of the list, the first and last items will be the nearest indexes again
        
        q->item.print();
    }
    
    else
        return false;
    
    return true;
}

//-------------------------------------------------------------------
// deleteStudent:
// Searches for the appropriate student, if the student is found, delete their information.
//-------------------------------------------------------------------

bool StudentList::deleteStudent(string n_first, string n_last){
    Node *q;                                        //node used for indexing
    Student s;                                      //student object used for comparison
    
    n_first = allCaps(n_first);                     
    n_last = allCaps(n_last);
    s.setName(n_first,n_last);                      //set the name of the student object using the inputted names
    
    q = first;
    while(q && !(q->item == s))                     //until we've hit the end of the list or found the item
        q = q->after;
    
    if(!q)                                          //if we can't find it
        return false;
    else if(!q->after){                             //if we've found it, but it's at the end of the list
        q->before->after = NULL;
        last = q->before;                           //make sure we still know where the end is
    }
    else if(!q->before){                            //if we've found it, but it's at the beginning of the list
        q->after->before = NULL;
        first = q->after;
    }
    else{                                           //we've found it, and it's in the middle of the list!
        q->before->after = q->after;
        q->after->before = q->before;
    }
    
    cout << "Student deleted: " << q->item.getLastName() << ", " << q->item.getFirstName() << endl;
    student_count--;
    delete q;                                       //need to make sure we're not leaking memory
    return true;
}
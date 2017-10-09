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
    Node *pNew;
    Node *q;
    pNew = new Node(s);
    if(!pNew){
        cout << "Error in dynamic allocation!" << endl;
        return false;
    }
    
    if(isEmpty()){
        first = pNew;
        last = pNew;
    }
    else{
        q = first;
        while(q && q->item < pNew->item){
            q = q->after;
        }
        
        if(!q){
            pNew->before = last->before;
            pNew->after = NULL;
            last = pNew; //i think this works]
            
        }
        else{
            pNew->before = q->before;
            if(!pNew->before)
                first = pNew;
            else
                q->before->after = pNew; //ayyy
            
            pNew->after = q;
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
    Node *p = first;
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
        average += p->item.getAverage();
        p = p->after;
    }
    
    average /= student_count;                //find the average
    
    return average;
}

//-------------------------------------------------------------------
// clear:
// Iterates through all of the nodes and deletes each one.
//-------------------------------------------------------------------
void StudentList::clear(void){
    Node *p, *q;
    p = first;
    while(p){
        q = p->after;
        delete p;
        p = q;
    }
    first = NULL;
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
    Node *q;
    Student s;
    
    q = first;
    
    n_first = allCaps(n_first);
    n_last = allCaps(n_last);
    s.setName(n_first,n_last);
    
    while(q && !(q->item == s) && (q->item < s))
        q = q->after;
    
    if(!q){
        cout << "Student not found, printing two nearest: " << endl << endl;
        last->item.print();
        first->item.print();
    }
    else if(q->item == s){
        cout << "Student found: " << endl;
        q->item.print();
    }
    else if (q->item > s) {
        cout << "Student not found, printing two nearest: " << endl << endl;
        
        if(q->before)
            q->before->item.print();
        else
            last->item.print();
        
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
    Node *q;
    Student s;
    
    n_first = allCaps(n_first);
    n_last = allCaps(n_last);
    s.setName(n_first,n_last);
    
    q = first;
    while(q && !(q->item == s))
        q = q->after;
    
    if(!q)
        return false;
    else if(!q->after){
        q->before->after = NULL;
        last = q->before;
    }
    else if(!q->before){
        q->after->before = NULL;
        first = q->after;
    }
    else{
        q->before->after = q->after;
        q->after->before = q->before;
    }
    
    cout << "Student deleted: " << q->item.getLastName() << ", " << q->item.getFirstName() << endl;
    student_count--;
    delete q;
    return true;
}
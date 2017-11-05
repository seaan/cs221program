// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   StudentTree.h
   AUTHOR: Sean Widmier
   DATE:   November 2, 2017
   COURSE: CS221-02, FALL 2017s

   Class StudentTree header file.  The methods for class StudentTree are 
   declared here. See StudentTree.cpp for implementation
*/
//***************************************************************************//

#ifndef STUDENTTREE_H
#define STUDENTTREE_H

#include "Student.h"
#include "utilities.h"

using namespace std;

class StudentTree;

class TreeNode { // a node in our binary tree
    Student item; // data item in the node
    TreeNode *left; // left child node
    TreeNode *right; // right child node
    TreeNode(Student); // constructor for new nodes
    friend StudentTree; // this makes private attributes visible to the friend
};

class StudentTree {
    TreeNode  *root;    // root node of the binary tree

    TreeNode *findNode(TreeNode*, Student);  // internal utility used to find a ptr to a node

    bool      insertNode(TreeNode*&, Student);  // internal recursive utility to find location and insert a new Student in the tree
    void      freeNode(TreeNode *); // internal utility to recursively free nodes
    void      printNodes(ostream &, TreeNode*);
    void      printNodesReverse(ostream &out, TreeNode *R);
    void preOrder(ostream &, TreeNode*, int, char); // ADDED
    void postOrder(ostream&, TreeNode*); // ADDED temporary
    int       countNodes(TreeNode *);

    // New for version 2
    void deleteNode(TreeNode* &);
    void getPredecessorItem(TreeNode *, Student &); 
    void doDelete(TreeNode* &, Student);

public:
    StudentTree();   // default constructor
   ~StudentTree();   // destructor

   void free();      // utility used to free all nodes allocated to a tree
   bool insert(Student);  // insert a student into the tree
   void remove(Student);  // remove a student from the tree
   bool find(Student);    // true if student is in the tree
   int  count();
   void display(ostream &, int); // print the tree values to the stream, in sort order

   // new for version 2
   void deleteItem(Student valueToDelete);
   
};


#endif /* STUDENTTREE_H */


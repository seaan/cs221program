#include "StudentTree.h"

// ***                  CREATED USING NETBEANS IDE                       ***  //
//***************************************************************************//
/* FILE:   StudentTree.cpp
   AUTHOR: Sean Widmier
   DATE:   November 2, 2017
   COURSE: CS221-02, FALL 2017

   Class StudentTree implementation file.  The methods for class StudentTree are 
   developed here. Please see StudentTree.h for the declaration of StudentTree.
 */
//***************************************************************************//

//-------------------------------------------------------------------
// StudentList Constructor:
// Constructor for the StudentList class, including parameters for creation.
//-------------------------------------------------------------------
#include "StudentTree.h"

TreeNode::TreeNode(Student s) { // node constructor
    item = s;
    left = NULL;
    right = NULL;
}

StudentTree::StudentTree() { // default constructor
    root = NULL;
}

StudentTree::~StudentTree() { // destructor
    free();
}

//****************************************************************************
// PRIVATE METHODS                                                    ********
//****************************************************************************

// this function takes a reference to the top of a tree, searches recursively
// until either the root contains the item or the tree is empty

void StudentTree::doDelete(TreeNode* &R, Student s) {
    if (R) { // tree is not empty
        if (s == (R->item)) // this is the value we want, delete the root node
            deleteNode(R);
        else if (s < (R->item)) // otherwise perform doDelete on the left subtree
            doDelete(R->left, s);
        else // otherwise perform doDelete on the right subtree
            doDelete(R->right, s);
    }
}

// once a node has been performed we need to remove and free that node
// this function deletes the node at the root of the current subtree (The node we want)

void StudentTree::deleteNode(TreeNode* &R) {

    Student data;
    TreeNode *tempPtr = R;
    if (R->left == NULL) // one of the simple cases, promote the other child up and delete this node
    {
        R = R->right;
        delete tempPtr;
    } else if (R->right == NULL) // same case, other side
    {
        R = R->left;
        delete tempPtr;
    } else // OTHERWISE this node has 2 children
    {
        getPredecessorItem(R->left, data);
        R->item = data;
        doDelete(R->left, data); // remove the predecessor data that has to be in a leaf node now
        // we are only swapping data up, no need to delete the tempPtr node here
    }

}

// We have the left subtree of a node that had 2 children. Search to the right to find
// the rightmost value in this subtree which would be the value right before our deleted node

void StudentTree::getPredecessorItem(TreeNode *R, Student &data) {
    while (R->right != NULL)
        R = R->right;

    data = R->item;
}

//-------------------------------------------------------------------
// private method - internal utility
// findNode: recursive function that searches for a node pointer to a
// node with the matching Student (searchtext)
// Can be used by other utilities that need to find a particular node.
//-------------------------------------------------------------------

TreeNode *StudentTree::findNode(TreeNode *R, Student s) {
    if (R == NULL)
        return NULL;
    else if (s == (R->item))
        return R;
    else if (s < (R->item))
        return findNode(R->left, s);
    else
        return findNode(R->right, s);
}

//-------------------------------------------------------------------
// private method - internal utility
// printNodes: recursive function that prints nodes from the starting 
// Node R.
// INORDER Traversal
//-------------------------------------------------------------------

void StudentTree::printNodes(ostream &out, TreeNode *R) {
    if (R != NULL) {
        printNodes(out, R->left);
        R->item.print();
        printNodes(out, R->right);
    }
}

//-------------------------------------------------------------------
// private method - internal utility
// preOrder: recursive function that prints nodes from the starting 
// Node R.  This print is formatted to show the structure of the 
// tree, left and right nodes at every level.
// PREORDER Traversal
//-------------------------------------------------------------------

void StudentTree::preOrder(ostream &out, TreeNode *R, int level, char mark) {
    for (int i = 0; i < level; i++) out << "   "; // let's indent each level of the tree so it
    // shows deeper nodes as pushed over to the right
    out << mark << ": ";
    if (R != NULL) {
        R->item.print();
        preOrder(out, R->left, level + 1, 'L');
        preOrder(out, R->right, level + 1, 'R');
    } else {
        printf("null\n");
    }
}

//-------------------------------------------------------------------
// private method - internal utility
// postOrder: recursive function that prints nodes from the starting 
// Node R.  
// POSTORDER Traversal
//-------------------------------------------------------------------

void StudentTree::postOrder(ostream &out, TreeNode *R) {
    if (R != NULL) {
        postOrder(out, R->left);
        postOrder(out, R->right);
        R->item.print();
    }
}

//-------------------------------------------------------------------
// private method - internal utility
// insertNode: recursive method to insert a node into the ordered 
// tree starting at the Referenced root node R.  
//-------------------------------------------------------------------

bool StudentTree::insertNode(TreeNode* &R, Student s) {
    if (R == NULL) {
        R = new TreeNode(s);
        return true;
    } else if (s == (R->item)) // node already exists!
        return false;
    else if (s == (R->item)) // insert the Student into left child tree
        return insertNode(R->left, s);
    else
        return insertNode(R->right, s); // otherwise, insert into right child tree
}


//-------------------------------------------------------------------
// private method - internal utility
// deleteNodes: recursive method to delete all nodes at each level of
// the tree.
//-------------------------------------------------------------------

void StudentTree::deleteNodes(TreeNode *R) {

    // TO BE DONE AS EXERCISE
}

//-------------------------------------------------------------------
// private method - internal utility
// countNodes: recursive method to count all nodes in
// the tree.
//-------------------------------------------------------------------

int StudentTree::countNodes(TreeNode *R) {

    // TO BE DONE AS EXERCISE
    return 0;
}

//****************************************************************************
// PUBLIC METHODS                                                     ********
//****************************************************************************

//-------------------------------------------------------------------------
// insert: Inserts a new Student into the tree. Will return false if
// Student is already in the tree and cannot be inserted.
// This function calls the internal recursive BST method to insert a 
// node in a tree.
//-------------------------------------------------------------------------

bool StudentTree::insert(Student s) { // insert a Student into the tree
    return insertNode(root, s);
}

//-------------------------------------------------------------------
// freeTree: Method used to free all nodes allocated to a Tree.  
// This calls the recursive method deleteNodes with the pointer
// to the root node as the starting point.
//-------------------------------------------------------------------

void StudentTree::free() {
    deleteNodes(root);
    root = NULL;
}

//-------------------------------------------------------------------------
// count
// returns a count of the elements stored in this tree.
// calls the recursive method countNodes starting at the root of the tree
//-------------------------------------------------------------------------

int StudentTree::count() {
    return countNodes(root);
}

//-------------------------------------------------------------------
// print: Method used to print all nodes stored in a Tree.  
// INORDER Traversal.
// It will print the tree nodes in sorted order,
// This calls the recursive method printNodes with the pointer
// to the root node as the starting point.
// Use ordering: 
//    1 - inorder
//    2 - preorder
//    3 - postorder
//-------------------------------------------------------------------

void StudentTree::display(ostream &out, int ordering) {
    switch (ordering) {
        case 1:
            printNodes(out, root);
            break;
        case 2:
            preOrder(out, root, 0, '>');
            break;
        default:
            postOrder(out, root);
    } // end switch
}


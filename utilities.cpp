/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "utilities.h"
#include <cctype>
using namespace std;
//   This function reads characters one at a   time from an   input stream untilthe end of the line
//   is cleared
void clearToEol(istream &in) {
    char nextChar;
    nextChar = in.get();
    while (nextChar != '\n' &&   !in.eof())
        nextChar =  in.get();
}

//   This function clears leading whitespace off a  line (tabs, blanks, new lines) until data is   found or   eof is   found
void clearLeadingWhitespace(istream &in) {
    char nextChar;
    nextChar = in.peek();
    while (!in.eof() &&   isspace(nextChar)) {
        in.get();  //   eat the whitespace character
        nextChar =  in.peek();
    }

}
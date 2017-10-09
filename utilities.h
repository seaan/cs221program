/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilities.h
 * Author: Sean Widmier
 *
 * Created on September 12, 2017, 12:03 PM
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

                                                    //Simple utilities used commonly across the program.
void clearToEol(istream &in);                       //Clears all characters until we reach the end of the line.
void clearLeadingWhitespace(istream &in);           //Clears leading whitespace before our data
void readArray(istream &in, float numbers[], int &count, int capacity);
string allCaps(string str);

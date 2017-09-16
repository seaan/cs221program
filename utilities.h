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
//   I  need some simple utilities that end up being used a lot
//   for example,

//    - jettisoning extra characters until the end of a  line is reached

void clearToEol(istream &in);
void clearLeadingWhitespace(istream &in);

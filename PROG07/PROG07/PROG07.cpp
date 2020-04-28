//**********************************************************************
//*                                                                    *
//* Program Name: PROG07S - Test for the presence of all required      *
//*                         money class overloaded operator and member *
//*                         functions in a money.h file.               *
//* Author:       CS246 Instructor                                     *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: January 2, 2008                                      *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program tests to see if an included "money.h" file contains   *
//* all required money class overloaded operator and member functions. *
//* The "money.h" file being tested must be in this programs folder.   *
//* If this program runs correctly after compiling and linking, the    *
//* "money.h" file does contain all required money class overloaded    *
//* operator and member functions.                                     *
//* NOTE: This program DOES NOT test the correct execution of these    *
//*       overloaded operators and member functions.  It ONLY tests    *
//*       for their presence in the included "money.h" file.           *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include<iostream>
#include "money.h"
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME     "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define COURSE_NUMBER   "CS246"  // PCC assigned course number
#define PROGRAM_NUMBER  "7S"     // Teacher assigned program number

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   money ob1, ob2, ob3; float random = 5.456f;

   // Print the program heading
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER
      << " " << COURSE_NAME
      << " - Program " << PROGRAM_NUMBER;
   cout << "\n=========================================================";

   // Print the "complied and linked properly" message
   cout << "\n\n  Your money.h compiled and linked properly, indicating"
      << "\n  all required overloaded operator and member functions"
      << "\n  are present. However this DOES NOT mean the functions"
      << "\n  are working correctly.   YOU MUST completely test all"
      << "\n  your functions yourself, to ensure their reliability.";

   ob2.set_dollars(8);
   ob2.set_cents  (27.62632f);

   cout << "\n\n" << ob2.get_total();

   ob1.set_dollars(6);
   ob1.set_cents  (54.345f);

   cout << "\n\n" << ob1.get_total();

   ob3.set_dollars(45);
   ob3.set_cents  (78.398f);

   cout << "\n\n" << ob3.get_total();

   cout << "\n\n" << ob1.get_total();

   // Normal program termination
   cout << "\n\n\n\n\n\n";
   return 0;
}
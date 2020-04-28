//**********************************************************************
//*                                                                    *
//* Program Name: PROG02 - Calculate geometric shapes                  *
//* Author:       Eric J. Cherubin                                     *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 11, 2019                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge the lines  in this C++ program are my own  original work, *
//* and none of the  lines in this C++  program have been  copied from *
//* anyone else,  unless I was specifically  authorized to do so by my *
//*                          CS246 instructor.                         *
//*                                                                    *
//*                                                                    *
//*                      Signed: ____________________________________  *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program calculates the following geometric shapes:            *
//*    The area of a circle                                            *
//*    The area of a rectangle                                         *
//*    The volume of a rectangular solid*                              *
//* and prints the specifications of these shapes.                     *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
using namespace std;

//**********************************************************************
//*                       Symbolic Constants                           *
//**********************************************************************
#define COURSE_NAME    "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define COURSE_NUMBER  "CS246"   // PCC assigned course number
#define PI             3.141593f // Math constant ratio of a circle
#define PROGRAM_NUMBER 2         // Teacher assigned program number

//**********************************************************************
//*                      Function Prototypes                           *
//**********************************************************************
void print_heading();
// Print the program heading
void get_dimensions(float geometric_input[]);
// Get the dimensions
void calculate_geometric_figures(float circle_diameter);
// Calculate the area of a circle
void calculate_geometric_figures(float rectangle_length, 
   float rectangle_width);
// Calculate the area of a rectangle
void calculate_geometric_figures(float rectangle_length,
   float rectangle_width, float rectangle_depth);
// Calculate the volume of a rectangular solid

//**********************************************************************
//*                        Main Function                               *
//**********************************************************************
int main()
{
   float circle_diameter,    // The diameter of a cirlce
         geometric_input[4], // The dimensions of the geometric shapes
         rectangle_depth,    // The depth of the rectangular solid
         rectangle_length,   // The length of a rectangle
         rectangle_width;    // The width of a rectangle

   // Print the program heading
   print_heading();

   // Get the dimensions
   get_dimensions(geometric_input);

   // Calculate the area of a circle, the area of a rectangle, and
   // the volume of a rectangular solid
   circle_diameter  = geometric_input[0];
   rectangle_length = geometric_input[1];
   rectangle_width  = geometric_input[2];
   rectangle_depth  = geometric_input[3];
   cout <<  "\nHere are the requested areas and volume:";
   cout <<  "\n========================================";
   calculate_geometric_figures(circle_diameter);
   calculate_geometric_figures(rectangle_length, rectangle_width);
   calculate_geometric_figures(rectangle_length, rectangle_width,
      rectangle_depth);
   
   // Say goodbye and terminate the program
   cout << "\n\nThanks for calculating geometric shapes today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                  Print the program heading                         *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER << " " << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\n       Calculate geometric shape areas and volume";
   return;
}

//**********************************************************************
//*                Get the rectangle specifications                    *
//**********************************************************************
void get_dimensions(float geometric_input[])
{
   cout << "\n\n\nEnter the geometric shape dimensions as follows:";
   cout << "\n    Circle diameter: ";
   cin  >> geometric_input[0];
   cout <<   "   Rectangle length: ";
   cin  >> geometric_input[1];
   cout <<   "    Rectangle width: ";
   cin  >> geometric_input[2];
   cout <<   "    Rectangle depth: ";
   cin  >> geometric_input[3];

   return;
}

//**********************************************************************
//*                Calculate the area of a circle                      *
//**********************************************************************
void calculate_geometric_figures(float circle_diameter)
{
   cout << "\nArea of a circle with diameter " << circle_diameter 
        << ":";
   cout << "\n   " << 0.25f * PI * (circle_diameter * circle_diameter)
	   << " square units";
  
   return;
}

//**********************************************************************
//*                Calculate the area of a rectangle                   *
//**********************************************************************
void calculate_geometric_figures(float rectangle_length,
   float rectangle_width)
{
   cout << "\nArea of a rectangle of length " << rectangle_length
        << " by width "                       << rectangle_width << ":";
   cout << "\n   " << rectangle_length * rectangle_width 
        << " square units";

   return;
}

//**********************************************************************
//*            Calculate the volume of a rectangular solid             *
//**********************************************************************
void calculate_geometric_figures(float rectangle_length,
   float rectangle_width, float rectangle_depth)
{
   cout << "\nVolume of a rectangular solid of " 
        << "length "  << rectangle_length 
        << ", width " << rectangle_width 
        << ", depth " << rectangle_depth << ":";
   cout << "\n   "    << rectangle_length * rectangle_width * 
	  rectangle_depth << " cubic units";

   return;
}
//**********************************************************************
//*                                                                    *
//* Program Name: PROG01 - Draw a rectangle                            *
//* Author:       Eric J. Cherubin                                     *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 7, 2019                                     *
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
//* This program asks for a length and width. Then, the program will   *
//* draw a rectangle using those specifications.                       *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME      "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define CS246            "CS246" // PCC assigned course number
#define MIN_RECT_LENGTH  1       // Minimum length for rectangle
#define MIN_RECT_WIDTH   1       // Minimum width for rectangle
#define PROGRAM_NUMBER   1       // Teacher assigned program number
#define RECTANGLE_BORDER '*'     // Border of drawn rectangle
#define RECTANGLE_CENTER ' '     // Center of drawn rectangle 
#define SCALE_FACTOR     1.5f    // Scales the rectangle 

//**********************************************************************
//*                         Program Structures                         *
//**********************************************************************
// The specifications of a rectangle
struct rectangle
{
   float area,      // Area of the rectangle (L x W) in square units
         length,    // Length of the rectangle in units
         perimeter, // Perimeter of the rectangle (2L + 2W) in units
         width;     // Width of the rectangle in units
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_rectangle(struct rectangle *p_user_rectangle);
   // Get the rectangle specifications
void draw_rectangle(float length, float width);
   // Draw the rectangle with given dimensions
void show_rectangle(struct rectangle user_rectangle);
   // Show the rectangle specifications

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   struct rectangle user_rectangle; // User rectangle specifications

   // Print the program heading
   print_heading();

   // Get the rectangle specifications
   get_rectangle(&user_rectangle);

   // Draw the rectangle and show the rectangle specifications
   draw_rectangle(user_rectangle.length, user_rectangle.width);
   show_rectangle(user_rectangle);

   // Say goodbye and terminate the program
   cout << "\n\nThanks for drawing a rectangle today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n      " << CS246 << " " << COURSE_NAME;
   cout << " - Program "        << PROGRAM_NUMBER;
   cout << "\n\n                   This program draws a rectangle";
   cout << "\n                    ==============================";
   return;
}

//**********************************************************************
//*                   Get the rectangle specifications                 *
//**********************************************************************
void get_rectangle(struct rectangle *p_user_rectangle)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> p_user_rectangle->length;

   cout << "Enter the rectangle width here: ";
   cin  >> p_user_rectangle->width;

   p_user_rectangle->area      = 
      p_user_rectangle->length * p_user_rectangle->width;
   p_user_rectangle->perimeter = 
      2.0f * (p_user_rectangle->length * p_user_rectangle->width);

   return;
}

//**********************************************************************
//*               Draw the rectangle with given dimensions             *
//**********************************************************************
void draw_rectangle(float length, float width)
{
   int rectangle_length, // Rectangle length dimension
       rectangle_width,  // Rectangle width dimension
       rows,             // Rectangle row dimensions
       columns;          // Rectangle column dimensions

   if (length < MIN_RECT_LENGTH || width < MIN_RECT_WIDTH)
   {
      cout << "\nA " << length << " by " << width 
           << " is too small to draw.";
      cout << "\nIt must be at least size 1 by 1 (length by width).";
   }
   else
   {
      rectangle_length = (int)length * SCALE_FACTOR;
      rectangle_width  = (int)width;

      cout << "\n\nHere is a picture of your rectangle:";
      cout << "\n";
      for (rows = 1; rows <= rectangle_width; rows++)
      {
         cout << "" << RECTANGLE_BORDER;
         for (columns = 1; columns < rectangle_length; columns++)
         {
            if (rows > 1 && rows < rectangle_width && 
               columns < rectangle_length - 1)
               cout << "" << RECTANGLE_CENTER;
            else
               cout << "" << RECTANGLE_BORDER;
         }
         cout << "\n";
      }
   }
   return;
}

//**********************************************************************
//*                 Show the rectangle specifications                  *
//**********************************************************************
void show_rectangle(struct rectangle user_rectangle)
{
   cout << "\n\nThe rectangle specifications are:";
   cout << "\n        Length = " << user_rectangle.length << " units";
   cout << "\n         Width = " << user_rectangle.width  << " units";
   cout << "\n          Area = " << user_rectangle.area   << " units";
   cout << "\n     Perimeter = " << user_rectangle.perimeter
                                                          << " units";
   return;
}
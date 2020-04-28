//**********************************************************************
//*                                                                    *
//* Program Name: PROG03 - Draw a picture of a rectangle and show      * 
//*                        specifications                              *
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
//* This program asks for a length and width of a rectangle,           *
//* draws a picture of a rectangle using those dimensions, and shows   *
//* the specifications of the rectangle.                               *
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
#define COURSE_NUMBER    "CS246" // PCC assigned course number
#define MIN_RECT_LENGTH  1.0f    // Minimum length for rectangle
#define MIN_RECT_WIDTH   1.0f    // Minimum width for rectangle
#define PROGRAM_NUMBER   3       // Teacher assigned program number
#define RECTANGLE_BORDER '*'     // Border of drawn rectangle
#define RECTANGLE_CENTER ' '     // Center of drawn rectangle 
#define SCALE_FACTOR     1.5f    // Rectangle length scale factor

//**********************************************************************
//*                          Class Definitions                         *
//**********************************************************************
// The specifications of a rectangle
class rectangle
{
   float area,      // Area of the rectangle (L x W) in square units
         length,    // Length of the rectangle in units
         perimeter, // Perimeter of the rectangle (2L + 2W) in units
         width;     // Width of the rectangle in units
public:
   // Constructor, create a rectangle
        rectangle     (float user_length, float user_width);
   // Destructor, destroy a rectangle
        ~rectangle    ();
   // Draw a picture of a rectangle with given dimensions
   void draw_rectangle();
   // Show rectangle specifications
   void show_rectangle();
};

//**********************************************************************
//*                          Create a rectangle                        *
//**********************************************************************
rectangle::rectangle(float user_length, float user_width)
{
   length    = user_length;
   width     = user_width;
   area      = length * width;
   perimeter = 2.0f * (length + width);
}

//**********************************************************************
//*                          Destroy a rectangle                       *
//**********************************************************************
rectangle::~rectangle()
{
   cout << "\n\nThe rectangle object is being destructed now";
}

//**********************************************************************
//*          Draw a picture of rectangle with given dimensions         *
//**********************************************************************
void rectangle::draw_rectangle()
{
   int columns,  // Columns of the rectangle
       i_length, // Integer value of rectangle length
       i_width,  // Integer value of rectangle width
       rows;     // Rows of the rectangle

   // Check the size of the rectangle dimensions
   if (length < MIN_RECT_LENGTH || width < MIN_RECT_WIDTH)
   {
      cout << "\nA " << length << " by " << width 
           << " is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_LENGTH << " by " 
           << MIN_RECT_WIDTH << "(length by width).";
   }
   else
   {
      // Scale the length of the rectangle
      i_length = int(length * SCALE_FACTOR);
      i_width  = int(width);

      // Print the title 
      cout << "\n\nHere is a picture of your rectangle:";
      cout << "\n";

      // Draw the top row and columns
      for (columns = 1; columns <= i_length; columns++)
         cout << "" << RECTANGLE_BORDER;
      cout << "\n";

      // Draw the middle row and columns
      if (i_width > 2)
      {
         for (rows = 1; rows < i_width - 1; rows++)
         {
            cout << "" << RECTANGLE_BORDER;
            for (columns = 1; columns <= i_length - 2; columns++)
               cout << "" << RECTANGLE_CENTER;
            cout << "" << RECTANGLE_BORDER;
            cout << "\n";
         }
      }

      // Draw the bottom row and columns
      if (i_width > 1)
      {
         for (columns = 1; columns <= i_length; columns++)
            cout << "" << RECTANGLE_BORDER;
         cout << "\n";
      }
   }
   return;
}

//**********************************************************************
//*                      Show rectangle specifications                 *
//**********************************************************************
void rectangle::show_rectangle()
{
   cout << "\n\nThe rectangle specifications are:";
   cout <<   "\n      Length = " << length    << " units";
   cout <<   "\n       Width = " << width     << " units";
   cout <<   "\n        Area = " << area      << " sq. units";
   cout <<   "\n   Perimeter = " << perimeter << " units";
   return;
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_rectangle(float *p_length, float *p_width);
   // Get the rectangle specifications

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   float length, // Length of the rectangle
         width;  // Width of the rectangle

   // Print the program heading
   print_heading();

   // Get the rectangle specifications
   get_rectangle(&length, &width);

   // Create the rectangle object
   rectangle user_rectangle(length, width);

   // Draw a picture of the rectangle and show the specifications
   user_rectangle.draw_rectangle();
   user_rectangle.show_rectangle();

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
   cout << "\n\n\n\n\n\n      " << COURSE_NUMBER 
	     << " "                  << COURSE_NAME
        << " - Program "        << PROGRAM_NUMBER;
   cout << "\n\n                   This program draws a rectangle";
   cout << "\n                     ==============================";
   return;
}

//**********************************************************************
//*                   Get the rectangle specifications                 *
//**********************************************************************
void get_rectangle(float *p_length, float *p_width)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> *p_length;

   cout <<       "Enter the rectangle width here: ";
   cin  >> *p_width;
   return;
}
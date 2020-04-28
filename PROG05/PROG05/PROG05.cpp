//**********************************************************************
//*                                                                    *
//* Program Name:  PROG05 - Calculate the Square Area and Circle Area  *
//*                         Ratio                                      *
//* Author:        Eric J. Cherubin                                    *
//* Installation:  Pensacola Christian College, Pensacola, Florida     *
//* Course:        CS246, Object-Oriented Programming and Design       *
//* Date Written:  March 25, 2019                                      *
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
//* This program asks for the diameter of a circle, then calculates    *
//* that circle's specifications and the specifications of a square    *
//* whose perimeter is equal to the circumference of that circle. The  *
//* ratio is then calculated and printed of the area of the square to  *
//* the area of the circle where the perimeter of the square exactly   *
//* equals to the circumference of the circle.                         *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
using namespace std;
class circle;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME           "Object-Oriented Programming and Design"
                                      // PCC assigned course name
#define COURSE_NUMBER         "CS246" // PCC assigned course number
#define MIN_DIAMETER          0       // Minimum diameter value
#define PI                    3.141593f 
                                      // Mathematical constant PI 
#define PROGRAM_NUMBER        5       // Teacher assigned program number
#define QUIT                  0       // Program exit value

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
// The specifications of a square
class square
{
   float area,      // Area of a square
         perimeter, // Perimeter of a square
         side;      // Length of the side of a square

public:
   // Constructors, create a square 
                 square         (float s)  {side      = s;
                                            area      = s * s;
                                            perimeter = 4.0f * s;};
                 square         ()         {};

   // Set the values
          void   set_area       (float a)  {area      = a;};
          void   set_perimeter  (float p)  {perimeter = p;};
          void   set_side       (float s)  {side      = s;};

   // Get the values
          float  get_area      ()          {return area;};
          float  get_perimeter ()          {return perimeter;};
          float  get_side      ()          {return side;};

   // Create a square using the specifications of the circle
          square create_square (circle circle);

   // Calculate the ratio of the square's area to the circle's area
   friend float  area_ratio    (circle circle, square square);
};

// The specifications of a circle
class circle
{
   float area,          // Area of a circle
         circumference, // Circumference of a circle
         diameter;      // Length of the diameter of a circle

public:
   // Constructors, create a circle
                circle                 (float d) {diameter      = d;
                                                  circumference = PI * d;
                                                  area          = 0.25f *
                                                    PI * (d * d);};
                circle                 ()        {};

   // Set the values
          void  set_area               (float a) {area          = a;};
          void  set_circumference      (float c) {circumference = c;};
          void  set_diameter           (float d) {diameter      = d;};

   // Get the values
          float  get_area              ()        {return area;};
          float  get_circumference     ()        {return circumference;};
          float  get_diameter          ()        {return diameter;};

   // Create square using the circle's specifications
   friend square square::create_square (circle circle);

   // Calculate the ratio of the square's area to the circle's area
   friend float  area_ratio            (circle circle, square square);
};

//**********************************************************************
//*          Create square using the circle's specifications           *
//**********************************************************************
square square::create_square(circle circle)
{
   square user_square(circle.get_diameter() * (PI / 4));
   return user_square;
}

//**********************************************************************
//*    Calculate the ratio of the square's area to the circle's area   *
//**********************************************************************
float area_ratio(circle circle, square square)
{
   return square.get_area() / circle.get_area();
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the heading
circle get_circle();
   // Get the circle's dimensions

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   circle circle; // A circle object
   square square; // A square object

   // Print the heading
   print_heading();

   // Loop processing area ratios until the user quits
   while (circle = get_circle(), circle.get_diameter() != QUIT)
   {
      // Print the circle's specifications
      cout << "\n\nThe circle's specifications are:";
      cout <<   "\n--------------------------------";
      cout <<   "\n        diameter: " << circle.get_diameter();
      cout <<   "\n   circumference: " << circle.get_circumference();
      cout <<   "\n            area: " << circle.get_area();

      // Create a square using the circle's specifications
      square = square.create_square(circle);

      // Print the square specifications
      cout << "\n\nThe square's specifications are:";
      cout <<   "\n--------------------------------";
      cout <<   "\n            side: " << square.get_side();
      cout <<   "\n       perimeter: " << square.get_perimeter();
      cout <<   "\n            area: " << square.get_area();

      // Calculate the ratio of the square's area to the circle's area
      cout << "\n\nRatio of the square's area to the circle's area is:";
      cout <<   "\n---------------------------------------------------";
      cout <<   "\n               <**** " << area_ratio(circle, square)
           <<   " ****>";
   }

   // Say goodbye and terminate the program
   cout << "\n\n\n  Goodbye, and I hope you learned something about the"
        <<     "\n ratio of the area of a square to the area of a circle,"
        <<     "\n where the perimeter of the square is exactly equal to"
        <<     "\n            the circumference of the circle.";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                          Print the heading                         *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n        "   << COURSE_NUMBER
        << " "                      << COURSE_NAME
        << " - Program "            << PROGRAM_NUMBER;
   cout << "\n        "
        << "========================================================";
   return;
}

//**********************************************************************
//*                       Get the circle's dimensions                  *
//**********************************************************************
circle get_circle()
{
   float diameter; // Diameter of the circle
   
   do
   {
      cout << "\n\n\nEnter a circle diameter greater than 0 "
           << "(or 0 to quit): ";
      cin  >> diameter;
      
      if (diameter < MIN_DIAMETER)
      {
         cout << "     Invalid: diameter must be greater than 0 "
              << " (or 0 to quit).";
      }
   } 
   while (diameter < MIN_DIAMETER && diameter != QUIT);

   circle circle(diameter);

   return circle;
}
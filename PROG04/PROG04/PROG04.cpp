//**********************************************************************
//*                                                                    *
//* Program Name:  PROG04 - Show the specifications of geometric shapes*
//* Author:        Eric J. Cherubin                                    *
//* Installation:  Pensacola Christian College, Pensacola, Florida     *
//* Course:        CS246, Object-Oriented Programming and Design       *
//* Date Written:  March 12, 2019                                      *
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
//* This program displays the dimensions and specifications of the     *
//* following three geometric shapes: the right triangle, square,      *
//* and rectangle.                                                     *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME           "Object-Oriented Programming and Design"
                                      // PCC assigned course name
#define COURSE_NUMBER         "CS246" // PCC assigned course number
#define PROGRAM_NUMBER        4       // Teacher assigned program number
#define RECTANGLE_ALLOC_ERR   3       // Rectangle exit value
#define RT_TRIANGLE_ALLOC_ERR 1       // Right triangle exit value
#define SQUARE_ALLOC_ERR      2       // Square exit value 

//**********************************************************************
//*                         Class Definitions                          *
//*                             Base Class                             *
//**********************************************************************
// A geometric shape
class geometric_shape
{
   int   total_sides,
         unique_sides;
   float area,
         perimeter;
public:
   // Show the geometric shape specifications
   virtual void  show_shape      ()        {}

   // Set the total sides, unique sides, area, and perimeter
           void  set_total_sides (int t_s) {total_sides = t_s;}
   
           void  set_unique_sides(int u_s) {unique_sides = u_s;}

           void  set_area        (float a) {area = a;}

           void  set_perimeter   (float p) {perimeter = p;}

   // Get the total sides, unique sides, area, and perimeter
           int   get_total_sides ()        {return total_sides;}

           int   get_unique_sides()        {return unique_sides;}

           float get_area        ()        {return area;}

           float get_perimeter   ()        {return perimeter;}

   // Display error message if memory cannot allocate
           void  fatal_error     (const char *p_geometric_shape, 
                                  int error_number);
};

//**********************************************************************
//*                           Derived Classes                          *
//**********************************************************************
class right_triangle : public geometric_shape
{
   char *p_right_triangle_1;
   float base,
         height,
         hypotenuse;

public:
   // Constructor, create a right triangle
        right_triangle (const char *p_preset_name, float default_base, 
                        float default_height);

   // Destructor, destroy a right triangle
		~right_triangle() {free(p_right_triangle_1);};

   // Show the right triangle specifications
   void show_shape     ();
};

class square : public geometric_shape
{
   char  *p_square_1;
   float side;

public:
   // Constructor, create a square
        square         (const char *p_preset_name, float default_side);
   
   // Destructor, destroy a square
        ~square        () {free(p_square_1);};
 
   // Show the square specifications
   void show_shape     ();
};

class rectangle : public geometric_shape
{
   char  *p_rectangle_1;
   float base,
         height;

public:
   // Constructor, create a rectangle
        rectangle      (const char *p_preset_name, float default_base, 
                        float default_height);

   // Destructor, destroy a rectangle
        ~rectangle     () {free(p_rectangle_1);};

   // Show the rectangle specifications
   void show_shape     ();
};

//**********************************************************************
//*          Display error message if memory cannot allocate           *
//**********************************************************************
void geometric_shape::fatal_error(const char *p_geometric_shape, 
   int error_number)
{
   cout << "\nError #" << error_number 
        << " occurred.";
   cout << "\nNot enough memory to allocate data.";
   cout << "\nThe program is aborting.";
   cout << "\n\n\n\n\n\n";
   exit (error_number);
   return;
}

//**********************************************************************
//*                        Create right triangle                       *
//**********************************************************************
right_triangle::right_triangle(const char *p_preset_name, 
                               float default_base, float default_height)
{
   cout << "\n\n\nCreating right triangle shape \"" << p_preset_name 
        << "\"";
   cout <<     "\n     with base = "                << default_base 
        << " and height = "                         << default_height;

   if ((p_right_triangle_1 = (char *) malloc(strlen(p_preset_name)+1)) 
	                                                             == NULL)
      fatal_error(p_preset_name, RT_TRIANGLE_ALLOC_ERR);

   strcpy_s(p_right_triangle_1, strlen(p_preset_name)+1, p_preset_name);

   base       = default_base;
   height     = default_height;

   hypotenuse = sqrtf ((base * base) + (height * height));
   set_total_sides    (3);
   set_unique_sides   (3);
   set_area           (0.5f * (base * height));
   set_perimeter      (base + height +
                       sqrtf ((base * base) + (height * height)));
}

//**********************************************************************
//*                Show the specifications of a triangle               *
//**********************************************************************
void right_triangle::show_shape()
{
   cout << "\n\n\nThe specifications of a right triangle shape are:";
   cout <<     "\n-------------------------------------------------";
   cout <<     "\nName of the shape:         \"" << p_right_triangle_1 
        <<     "\"";
   cout <<     "\nTotal number of sides:     "   << get_total_sides();
   cout <<     "\nNumber of unique sides:    "   << get_unique_sides();
   cout <<     "\nLength of base:            "   << base;
   cout <<     "\nLength of height:          "   << height;
   cout <<     "\nLength of hypotenuse:      "   << hypotenuse;
   cout <<     "\nArea:                      "   << get_area();
   cout <<     "\nPerimeter:                 "   << get_perimeter();
   return;
}

//**********************************************************************
//*                          Create a square                           *
//**********************************************************************
square::square(const char *p_preset_name, float default_side)
{
   cout << "\nCreating square shape \"" << p_preset_name << "\"";
   cout << "\n     with side = "        << default_side;

   if ((p_square_1 = (char *) malloc(strlen(p_preset_name) + 1)) == NULL)
      fatal_error(p_preset_name, SQUARE_ALLOC_ERR);

   strcpy_s(p_square_1, strlen(p_preset_name) + 1, p_preset_name);

   side = default_side;

   set_total_sides  (4);
   set_unique_sides (1);
   set_area         (side * side);
   set_perimeter    (4.0f * side);
}

//**********************************************************************
//*                Show the specifications of a square                 *
//**********************************************************************
void square::show_shape()
{
   cout << "\n\n\nThe specifications of a square shape are:";
   cout <<     "\n-----------------------------------------";
   cout <<     "\nName of the shape:         \"" << p_square_1 << "\"";
   cout <<     "\nTotal number of sides:     "   << get_total_sides();
   cout <<     "\nNumber of unique sides:    "   << get_unique_sides();
   cout <<     "\nLength of a side:          "   << side;
   cout <<     "\nArea:                      "   << get_area();
   cout <<     "\nPerimeter:                 "   << get_perimeter();
   return;
}


//**********************************************************************
//*                        Create a rectangle                          *
//**********************************************************************
rectangle::rectangle(const char *p_preset_name, float default_base, 
                     float default_height)
{
   cout << "\nCreating rectangle shape \"" << p_preset_name << "\"";
   cout << "\n     with base = "           << default_base 
        << " and height = "                << default_height;

   if ((p_rectangle_1 = (char *) malloc(strlen(p_preset_name) + 1))
                                                                == NULL)
      fatal_error(p_preset_name, RECTANGLE_ALLOC_ERR);

   strcpy_s(p_rectangle_1, strlen(p_preset_name) + 1, p_preset_name);

   base   = default_base;
   height = default_height;

   set_total_sides (4);
   set_unique_sides(2);
   set_area        (base * height);
   set_perimeter   (2.0f * (base + height));
}

//**********************************************************************
//*                 Show the specifications of a rectangle             *
//**********************************************************************
void rectangle::show_shape()
{
   cout << "\n\n\nThe specifications of a rectangle shape are:";
   cout <<     "\n--------------------------------------------";
   cout <<     "\nName of the shape:         \"" << p_rectangle_1 
        <<     "\"";
   cout <<     "\nTotal number of sides:     "   << get_total_sides();
   cout <<     "\nNumber of unique sides:    "   << get_unique_sides();
   cout <<     "\nLength of base:            "   << base;
   cout <<     "\nLength of height:          "   << height;
   cout <<     "\nArea:                      "   << get_area();
   cout <<     "\nPerimeter:                 "   << get_perimeter();
   return;
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the heading

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   geometric_shape *p_geometric_shape; // Points to a geometric shape

   // Print the heading
   print_heading();

   // Create a right triangle, a square, and a rectangle
   right_triangle right_triangle_1("RIGHT-TRIANGLE-1", 5.99f, 11.99f);
   square         square_1        ("SQUARE-1", 11.99f);
   rectangle      rectangle_1     ("RECTANGLE-1", 11.99f, 5.99f);

   // Show the specifications of a right triangle, a square, 
   // and a rectangle
   p_geometric_shape = &right_triangle_1;
   p_geometric_shape->show_shape();
   p_geometric_shape = &square_1;
   p_geometric_shape->show_shape();
   p_geometric_shape = &rectangle_1;
   p_geometric_shape->show_shape();

   // Say goodbye and terminate the program
   cout << "\n\n\nThanks for shaping things up today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                          Print the heading                         *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n  " << COURSE_NUMBER
        << " "              << COURSE_NAME
        << " - Program "    << PROGRAM_NUMBER;
   cout << "\n\n   The specifications of straight-sided geometric shapes";
   cout <<   "\n   =====================================================";
   return;
}
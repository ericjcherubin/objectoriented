//**********************************************************************
//*                                                                    *
//* Program Name:  PROG08 - Demonstrate a Vector Container             *
//* Author:        Eric J. Cherubin                                    *
//* Installation:  Pensacola Christian College, Pensacola, Florida     *
//* Course:        CS246, Object-Oriented Programming and Design       *
//* Date Written:  April 29, 2019                                      *
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
//* This program demonstrates how to use a vector container to         *
//* contain objects. An empty vector container is created and objects  *
//* are added to, deleted from, inserted onto, extended onto the end   *
//* of, and deleted from the end of the vector container. Indexes,     *
//* iterators, and reverse iterators are used to display the contents  *
//* of the vector container.                                           *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define COURSE_NUMBER      "CS246" // PCC assigned course number
#define PROGRAM_NUMBER     8       // Teacher assigned program number

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
// The cubes
class cubes
{
   int cube;

public:
   // Constructors, create a cube
       cubes    ()      {cube = -1;};
       cubes    (int i) {cube = (int)pow (i, 3);};

   // Get the cubed number
   int get_cube ()      {return cube;};
};

//**********************************************************************
//*                    Compare the cubed objects                       *
//**********************************************************************
bool operator< (cubes a, cubes b) {return a.get_cube() < b.get_cube();}
bool operator==(cubes a, cubes b) {return a.get_cube() == b.get_cube();}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the heading
void show_vector(vector<cubes> &v);
   // Show the vector container

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   int i;                                // The index of a vector container
   vector<cubes> v;                      // A vector container
   vector<cubes>::iterator p_v;          // Points to a vector container
   vector<cubes>::reverse_iterator rp_v; // Points to the end of a 
                                         // vector container

   // Print the heading
   print_heading();

   // Show the empty vector container
   cout << "\n\n\nHere is the starting empty cubes vector:";
   show_vector(v);

   // Add the first 6 cubed numbers to the vector container
   cout <<   "\n\nAdding the first 6 cubes to the vector:";
   for (i = 0; i < 6; i++)
      v.push_back(cubes(i));
   show_vector(v);

   // Delete the even cubed numbers from the vector container
   cout << "\n\nDeleting the even cubes from the vector:";
   for (i = 0; i < (int)v.size(); i++)
      v.erase(v.begin() + i);
   show_vector(v);

   // Insert the even cubed numbers back into the vector container 
   cout << "\n\nInserting the even cubes back into the vector:";
   for (i = 0; i < (int)v.size(); i+=2)
      v.insert(v.begin() + i, i);
   show_vector(v);

   // Add the next 4 cubed numbers to the end of the vector container 
   cout << "\n\nAdding the next 4 cubes to the end of the vector:";
   for (i = 6; i < 10; i++)
      v.insert(v.end(), i);
   show_vector(v);

   // Add 4 empty cubed numbers to the vector container
   cout << "\n\nAdding 4 empty cubes to the end of the vector:";
   for (i = 10; i < 14; i++)
      v.push_back(cubes());
   show_vector(v);

   // Remove the last 4 empty cubed numbers from the vector container
   cout << "\n\nRemoving the last 4 empty cubes from the vector:";
   for (i = 1; i < 5; i++)
      v.pop_back();
   show_vector(v);

   // Print the cubed numbers with an iterator and a reverse iterator
   cout << "\n\nPrinting the cubes with an iterator," 
        << " then with a reverse iterator:";
   cout << "\n ";
   for (p_v = v.begin(); p_v != v.end(); p_v++)
      cout << " " << p_v->get_cube();
   cout << "\n ";
   for (rp_v = v.rbegin(); rp_v != v.rend(); rp_v++)
      cout << " " << rp_v->get_cube();

   // Clear out the vector container
   cout << "\n\nRemoving all cubes from the vector:";
   v.clear();
   show_vector(v);

   // Say goodbye and terminate the program
   cout << "\n\n\nThanks for demonstrating a vector container today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                          Print the heading                         *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n" << COURSE_NUMBER
        << " "              << COURSE_NAME
        << " - Program "    << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\n A Simple Demonstration Of The C++ STL Vector Container";
   return;
}

//**********************************************************************
//*   Show the specifications and contents of the vector container     *
//**********************************************************************
void show_vector(vector<cubes> &v)
{
   int i,       // Index of the vector container
       sum = 0; // Sum of all the cubed numbers

   for (i = 0; i < (int)v.size(); i++)
      sum += v[i].get_cube();

   cout << "\n  Size: "     << v.size() 
        << " - Sum: "       << sum 
        << " - Capacity: "  << v.capacity()
        << " - Max size: "  << v.max_size();
   cout << "\n  Cubes Vector contents: ";

   for (i = 0; i < (int)v.size(); i++)
      cout << " " << v[i].get_cube();
}
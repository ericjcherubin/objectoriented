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

#include <iostream>
#include "pch.h"
using namespace std;

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
class money
{
   int cents,
       dollars;
   
public:
        money       ()             {dollars = 0; cents = 0;};
        money       (float amount) {};
   
   void set_dollars (float amount) {dollars = (int)amount;};
   void set_cents   (float amount);
   
   float get_total  ()             {return dollars; return cents;};
   
   // Overloaded operators
   money operator=  (money op2);
   money operator+  (money op2);
   money operator-  (money op2);
   money operator*  (money op2);
   money operator/  (money op2);
   money operator+= (money op2);
   money operator== (money op2);
   money operator!= (money op2);
   money operator<< (money op2);
   money operator>> (money op2);
   money operator++ ();
   money operator++ (int notused);
   
   // Left and right shift
   // Shift the digits not the decimal point
   // Do a decimal shift not a binary shift
   
   // Prefix and Postfix
   // Increment the dollar amount by 1 not the cents
};

void money::set_cents(float amount)
{
   
   return;
}

money money::operator=(money op2)
{  
   dollars = op2.dollars;
   cents   = op2.cents;
   
   return *this;
}

money money::operator+(money op2)
{
   money temp_money;

   temp_money.dollars = dollars + op2.dollars;
   temp_money.cents   = cents + op2.cents;

   return temp_money;
}

money money::operator-(money op2)
{
   money temp_money;

   temp_money.dollars = dollars - op2.dollars;
   temp_money.cents   = cents - op2.cents;

   return temp_money; 
}

money money::operator*(money op2)
{
   money temp_money;

   temp_money.dollars = dollars * op2.dollars;
   temp_money.cents   = cents * op2.cents;

   return temp_money;
}

money money::operator/(money op2)
{
   money temp_money;

   if (op2.dollars == 0 && op2.cents == 0)
   {
      cout << "Warning: a divide by 0.00 operation "
           << "cannot be done!";
      cout << "\nThe result of this operation is being "
           << "set to $0.00!";

      temp_money.dollars = 0;
      temp_money.cents   = 0;
   }
   else
   {
      temp_money.dollars = dollars / op2.dollars;
      temp_money.cents   = cents / op2.cents;
   }

   return temp_money;
}

money money::operator+=(money op2)
{
   dollars = dollars + op2.dollars;
   cents   = cents + op2.cents;

   return *this;
}

money money::operator==(money op2)
{
   return (dollars == op2.dollars && 
           cents == op2.cents);
}

money money::operator!=(money op2)
{
   return (dollars != op2.dollars &&
           cents   != op2.cents);
}

// Shift operators
money money::operator<<(money op2)
{
   op2.dollars = op2.dollars * 10;
   
   dollars = op2.dollars;

   return *this;
}

money money::operator>>(money op2)
{
   op2.dollars = op2.dollars / 10;

   dollars = op2.dollars;

   return *this;
}

money money::operator++()
{
   ++dollars;

   return *this;
}

money money::operator++(int notused)
{
   dollars++;

   return *this;
}
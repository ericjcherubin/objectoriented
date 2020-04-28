//**********************************************************************
//*                                                                    *
//* Program Name: Money.h - Manipulate money amounts                   *
//* Author:       CS246 Instructor                                     *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: April 25, 2018                                       *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This class will manipulate the dollars and cents using various     *
//* operators.                                                         *
//*                                                                    *
//**********************************************************************

#include <iostream>
#include "pch.h"
using namespace std;

//**********************************************************************
//*                           Class Definitions                        *
//**********************************************************************
// The money amount
class money
{
   int cents,   // The amount of cents
       dollars; // The amount of dollars
   
public:
   // Constructors, create a money amount
        money       ()             {dollars = 0; cents = 0;};
        money       (float amount) {set_dollars(amount); 
                                    set_cents(amount);};
   // Set the data members
   void set_dollars (float amount) {dollars = (int)amount;};
   void set_cents   (float amount);
   
   // Get the data members
   float get_total  ()             {return (float)(dollars + 
                                    (float)cents / 100);};
   
   // Overloaded operators
   money operator=  (money money_amount);
   money operator+  (money money_amount);
   money operator-  (money money_amount);
   money operator*  (money money_amount);
   money operator/  (money money_amount);
   money operator+= (money money_amount);
   int   operator== (money money_amount);
   int   operator!= (money money_amount);
   money operator<< (int number_of_shifts);
   money operator>> (int number_of_shifts);
   money operator++ ();
   money operator++ (int not_used);
};

//**********************************************************************
//*                            Set the cents                           *
//**********************************************************************
void money::set_cents(float amount)
{
   float negative_amount; // The negative cents amount

   // Remove the dollar amount
   amount -= (int)amount;
   negative_amount = -amount;

   // Round up the cents
   amount += 0.005f;
   negative_amount -= 0.005f;

   // Shift the numbers to the left
   amount *= 100;
   negative_amount *= 100;

   // Get rid of the decimals
   cents = (int)amount;

   // Check if cents are greater than 99 and if negative cents are less
   // than -99
   if (cents > 99)
   {
      cents -= 100;
      dollars += 1;
   }
   if (negative_amount < -99)
   {
      negative_amount += 100;
      dollars -= 1;
   }
   return;
}

//**********************************************************************
//*                       Copy the dollars and cents                   *
//**********************************************************************
money money::operator=(money money_amount)
{  
   dollars = money_amount.dollars;
   cents   = money_amount.cents;
   
   return *this;
}

//**********************************************************************
//*                    Add the dollars and add the cents               *
//**********************************************************************
money money::operator+(money money_amount)
{
   money temp_money; // Temporary variable for money

   temp_money.dollars = dollars + money_amount.dollars;
   temp_money.cents   = cents + money_amount.cents;

   return temp_money;
}

//**********************************************************************
//*               Subtract the dollars and subtract the cents          *
//**********************************************************************
money money::operator-(money money_amount)
{
   money temp_money; // Temporary variable for money

   temp_money.dollars = dollars - money_amount.dollars;
   temp_money.cents   = cents - money_amount.cents;

   return temp_money; 
}

//**********************************************************************
//*              Multiply the dollars and multiply the cents           *
//**********************************************************************
money money::operator*(money money_amount)
{
   money temp_money; // Temporary variable for money

   temp_money.dollars = dollars * money_amount.dollars;
   temp_money.cents   = cents * money_amount.cents;

   return temp_money;
}

//**********************************************************************
//*                Divide the dollars and divide the cents             *
//**********************************************************************
money money::operator/(money money_amount)
{
   money temp_money; // Temporary variable for money

   if (money_amount.dollars == 0 && money_amount.cents == 0)
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
      temp_money.dollars = dollars / money_amount.dollars;
      temp_money.cents   = cents / money_amount.cents;
   }

   return temp_money;
}

//**********************************************************************
//*                   Add the dollars and add the cents                *
//**********************************************************************
money money::operator+=(money money_amount)
{
   dollars = dollars + money_amount.dollars;
   cents   = cents + money_amount.cents;

   return *this;
}

//**********************************************************************
//*    Compare the dollars and compare the cents if both are equal     *
//**********************************************************************
int money::operator==(money money_amount)
{
   return (dollars == money_amount.dollars && 
           cents == money_amount.cents);
}

//**********************************************************************
//*   Compare the dollars and compare the cents if both are not equal  *
//**********************************************************************
int money::operator!=(money money_amount)
{
   return (dollars != money_amount.dollars &&
           cents   != money_amount.cents);
}

//**********************************************************************
//*                     Shift the digits to the left                   *
//**********************************************************************
money money::operator<<(int number_of_shifts)
{  
   int power_counter,     // The power counter
       power_of_ten = 10; // The powers of 10

   for (power_counter = 1; power_counter < number_of_shifts; 
        power_counter++)
      power_of_ten *= 10;

   dollars *= power_of_ten;
   cents   *= power_of_ten;
   return *this;
}

//**********************************************************************
//*                     Shift the digits to the right                  *
//**********************************************************************
money money::operator>>(int number_of_shifts)
{
   int power_counter,     // The power counter
       power_of_ten = 10; // The powers of 10

   for (power_counter = 1; power_counter < number_of_shifts;
      power_counter++)
      power_of_ten *= 10;

   dollars /= power_of_ten;
   cents   /= power_of_ten;

   return *this;
}

//**********************************************************************
//*                  Add one to the dollar using prefix                *
//**********************************************************************
money money::operator++()
{
   ++dollars;
   return *this;
}

//**********************************************************************
//*                  Add one to the dollar using postfix               *
//**********************************************************************
money money::operator++(int not_used)
{
   dollars++;
   return *this;
}
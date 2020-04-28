//**********************************************************************
//*                                                                    *
//* Program Name:  PROG06 - A Database of Employee Bonus Records       *
//* Author:        Eric J. Cherubin                                    *
//* Installation:  Pensacola Christian College, Pensacola, Florida     *
//* Course:        CS246, Object-Oriented Programming and Design       *
//* Date Written:  April 11, 2019                                      *
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
//* This program asks for company information such as the name of the  *
//* company, the year of the bonuses that are given to the employees,  *
//* the number of employees, and the amount of the bonuses. The        *
//* program asks to enter each employee with the number of service     *
//* years each employee served in the company. The bonus amounts and   *
//* the year hired are calculated prints the employee information in a *
//* table form unsorted. The program sorts the employees and displays  *
//* the employees in a table form that is sorted in descending order.  *
//*                                                                    *
//**********************************************************************

#include "pch.h"
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define COMPANY_ALLOC_ERR  1       // Allocation error for company
#define COURSE_NUMBER      "CS246" // PCC assigned course number
#define EMPLOYEE_ALLOC_ERR 3       // Allocation error for employee
#define MAX_NAME_LENGTH    80      // Minimum diameter value
#define NAME_ALLOC_ERR     2       // Allocation error for company name
#define PROGRAM_NUMBER     6       // Teacher assigned program number

//**********************************************************************
//*                         Program Structures                         *
//**********************************************************************
// The company information
struct company_information
{
   float bonus_amount;        // Bonus amount 
   int   bonus_year,          // Year of bonus amounts
         number_of_employees; // Number of employees   
   char  *p_company_name;     // Points to a company name

};

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
// The database of employee bonus records
class employee_bonus_record
{
   int   employee_id,   // Employee ID number
         service_years, // Number of service years
         year_hired;    // Year that employee got hired
   float bonus_amount;  // The bonus amount that employee received

public:
   // Set the data members
   void   set_employee_id   (int e_i)   {employee_id = e_i;};
   void   set_service_years (int s_y)   {service_years = s_y;};
   void   set_year_hired    (int y_h)   {year_hired = y_h;};
   void   set_bonus_amount  (float b_a) {bonus_amount = b_a;};

   // Get the data members
   int    get_employee_id   ()          {return employee_id;};
   int    get_service_years ()          {return service_years;};
   int    get_year_hired    ()          {return year_hired;};
   float  get_bonus_amount  ()          {return bonus_amount;};

   // Destructor, delete a database of employee bonus records
   ~employee_bonus_record   ()          {cout << 
                                          "\n\nDestuctor executing ...";};
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_instructions();
   // Print the instructions
company_information *get_company_information();
   // Get the company information
employee_bonus_record *get_employees(company_information 
                                     company_information);
   // Get the employees' information
void print_employees(employee_bonus_record *p_employee_record_start, 
                     int number_of_employees, 
                     const char *p_sorted_message);
   // Print the employees
void sort_employees(employee_bonus_record *p_employee_record_start, 
                    int number_of_employees);
   // Sort the employees in ascending order of service years
void fatal_error(int error_number, const char *function_name, 
                 const char *memory_type);
   // Display error message

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   company_information   *p_company_information;   
                                   // The company information
   employee_bonus_record *p_employee_bonus_record; 
                                   // Database of employee bonus records

   // Print the instructions
   print_instructions();

   // Get the company information and display the information
   p_company_information = get_company_information();
   cout << "\n\nCompany Name:        "  
        << p_company_information->p_company_name;
   cout <<   "\nYear of the bonuses: "  
        << p_company_information->bonus_year; 
   cout <<   "\nNumber of employees: "  
        << p_company_information->number_of_employees;
   cout <<   "\nBonus per year:      $" 
        << p_company_information->bonus_amount;

   // Get the employees' information
   p_employee_bonus_record = get_employees(*p_company_information);

   // Print the employees in unsorted order
   print_employees(p_employee_bonus_record, 
                   p_company_information->number_of_employees, 
                   "IN UNSORTED ORDER");

   // Sort the employees in ascending order of service years
   sort_employees(p_employee_bonus_record, 
                  p_company_information->number_of_employees);

   // Print the employees in descending order
   print_employees(p_employee_bonus_record,
                   p_company_information->number_of_employees,
                   "IN SORTED ORDER");

   // Free the memory of company information and database of employee 
   // bonus records
   delete p_company_information;
   delete [] p_employee_bonus_record;

   // Say goodbye and terminate the program
   cout << "\n\n\nThanks for processing employee bonuses today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                     Print the instructions                         *
//**********************************************************************
void print_instructions()
{
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER
        << " "            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n"
        <<   "========================================================";
   cout << "\nThis program asks for information about your company and";
   cout << "\nabout each employee. It then calculates the bonus amount";
   cout << "\nowed each employee based on the number of service years.";
   return;
}

//**********************************************************************
//*                    Get the company information                     *
//**********************************************************************
company_information *get_company_information()
{
   company_information *p_company_information = NULL;  
                                        // Points to company information
   char                company_name[MAX_NAME_LENGTH+1];  
                                        // Company name

   // Allocate memory for company information
   try
   {
      p_company_information = new company_information;
   }
   catch (bad_alloc xa)
   {
      fatal_error(COMPANY_ALLOC_ERR, "get_company_information", 
                  "comapny_information");
   }

   // Prompt for company name
   cout << "\n\n\nEnter the name of your company here (no spaces): ";
   cin  >> company_name;

   // Allocate memory for company name
   try
   {
      p_company_information->p_company_name = 
                                         new char[MAX_NAME_LENGTH + 1];
   }
   catch(bad_alloc xa)
   {
      fatal_error(NAME_ALLOC_ERR, "get_company_information", "string");
   }

   // Copy name to company information
   strcpy_s(p_company_information->p_company_name, 
            strlen(company_name)+1, company_name);

   do
   {
      // Prompt for number of employees
      cout <<    "Enter your number of employees (1 or more): ";
      cin  >> p_company_information->number_of_employees;

      if (p_company_information->number_of_employees < 1)
         cout << "     The number of employees must be 1 or more.";
   }
   while (p_company_information->number_of_employees < 1);

   // Prompt for the year of bonuses
   cout << "Enter the year in which the bonuses are given (YYYY): ";
   cin  >> p_company_information->bonus_year;

   // Prompt for the amount of the yearly bonus
   cout << "Give the yearly bonus amount per employee (in dollars): ";
   cin  >> p_company_information->bonus_amount;

   // Return pointer to company information
   return p_company_information;
}

//**********************************************************************
//*                    Get the employee information                    *
//**********************************************************************
employee_bonus_record *get_employees(company_information 
                                     company_information)
{
   int employee_id = 0, // Employee ID number
       service_years;   // Number of service years
   employee_bonus_record *p_employee_start = NULL, 
                        // Points to a database of employee bonus records
                         *p_employee; 
                        // Points to every employee bonus record

   // Allocate memory for the employee bonus record
   try
   {
      p_employee_start = 
         new employee_bonus_record[company_information.number_of_employees];
   }
   catch (bad_alloc xa)
   {
      fatal_error(EMPLOYEE_ALLOC_ERR, "get_employees()", 
                  "employee_bonus_record");
   }

   p_employee = p_employee_start;

   // Loop processing employee bonus records
   do
   {
      // Loop processing service years 
      do
      {
         employee_id += 1;

         cout << "\n\nEnter the number of service years of employee #" 
              << employee_id;
         cout << "\nEnter 0 (zero) if this employee does not exist: ";
         cin  >> service_years;

         if (service_years < 0)
         {
            cout << "\n   The service years must be 0 or greater.";
            cout << "\n   Please reenter the number of service years.";
         }
      }
      while (service_years <= 0);

      // Check for valid employee ID 
      if (employee_id != 0)
      {
         p_employee->set_employee_id  (employee_id);
         p_employee->set_service_years(service_years);
         p_employee->set_year_hired   (company_information.bonus_year - 
                                         service_years);
         p_employee->set_bonus_amount (company_information.bonus_amount * 
                                         service_years);
         p_employee++;
      }
   }
   while((p_employee-p_employee_start) < 
          company_information.number_of_employees);

   // Return pointer to database of employee bonus record
   return p_employee_start;
}
//**********************************************************************
//*                       Print every employee                         *
//**********************************************************************
void print_employees(employee_bonus_record *p_employee_record_start,
   int number_of_employees, const char *p_sorted_message)
{
   employee_bonus_record *p_employee_record; // Points to every employee

   cout << "\n\nHere is the employee database, " << p_sorted_message 
        << ":";
   cout <<   "\n====================================================";
   cout <<   "\nEmployee Id   Service Years   Year Hired   Bonus Amt";
   cout <<   "\n-----------   -------------   ----------   ---------";

   for (p_employee_record = p_employee_record_start; 
       (p_employee_record-p_employee_record_start) < number_of_employees;
        p_employee_record++)
   {
      cout << "\n     "         << p_employee_record->get_employee_id()
           << "               " << p_employee_record->get_service_years()
           << "            "    << p_employee_record->get_year_hired()
           << "        $"       << p_employee_record->get_bonus_amount();
   }

   return;
}

//**********************************************************************
//*      Sort the employees in ascending order of service years        *
//**********************************************************************
void sort_employees(employee_bonus_record *p_employee_record_start,
   int number_of_employees)
{
   employee_bonus_record *p_employee,        
                                      // Points to every employee
                         *p_employee_record, 
                                      // Points to every employee
                         temp_employee;      
                                      // Temporary employee for the swap

   for (p_employee = p_employee_record_start;
       (p_employee - p_employee_record_start) < number_of_employees;
        p_employee++)
   {
      for (p_employee_record = p_employee+1; 
          (p_employee_record-p_employee_record_start) <
           number_of_employees; p_employee_record++)
      {
         if (p_employee->get_service_years() < 
             p_employee_record->get_service_years())
         {
            temp_employee      = *p_employee;
            *p_employee        = *p_employee_record;
            *p_employee_record = temp_employee;
         }
      }
   }
   return;
}

//**********************************************************************
//*             Display error message if allocation failed             *
//**********************************************************************
void fatal_error(int error_number, const char *function_name, 
                 const char *memory_type)
{
   cout << "\nError #"                        << error_number
        << " occurred in "                    << function_name;
   cout << "\nUnable to allocate memory for " << memory_type;
   cout << "\nThe program is aborting.";
   exit(error_number);
}
#pragma once
#include "lists.h"

// Function used to call the public hire methods of both the master list of employees and the list of a employee level.
// Takes in all of the lists as parameters rather than asking user for the new hire's level outside of the function.
void hireNewEmployee(ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C);

// Function used to call the public print all method of a given list
// Takes in all of the level lists as parameters for the same reason as the hireNewEmployee function.
void printLevel(ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C);

// Returns the desired level for an employee, an integer between 0 - 3.
int getEmployeeLevel();

// Function call's the public getEmployeeLevel method and getMentorshipInfo and displayed the returned information.
// Takes in the master list as a parameter.
void getEmployeeInfo(ListOfEmployees &L);

// Function used to call the public changeLevel method of the master list and hires the employee to the new level as well as fires employee from their pervious level.
// Takes in all of the lists as parameters for the same reason as the hireNewEmployee function.
void changeEmployeeLevel(ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C);

// Function used to call the public fire methods of both the master list of employees and the list of a employee level.
// Takes in all of the lists as parameters for the same reason as the hireNewEmployee function.
void terminateEmployee(ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C);

// Function used to call the public createMentorship method of the master list.
// Takes in the master list as a parameter.
void createNewMentorship(ListOfEmployees &L);

// Function used to call the public endMentorship method of the master list.
// Takes in the master list as a parameter.
void endMentorship(ListOfEmployees &L);

// Function used to call the public getMentorshipInfo method of the master list.
// Takes in the master list as a parameter.
void getMentorshipInfo(ListOfEmployees &L);

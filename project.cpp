#include "project.h"
#include <string>
#include <iostream>



void printMenu()
{
    std::cout << "\nH: Print help menu\nI: Insert a new employee\nT: Terminate an employee\nG: Get an employee's information\nC: Change an employee's level\nP: Print all employees of a level\nA: Print all employees\nN: Create a new mentorship pair\nE: End mentorship\nB: Print all currant mentorships\nJ: Get mentorship information of an employee\nQ: Quit" << std::endl;
}

void hireNewEmployee (ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C)
{
    std::string name;
    int level;

    std::cout << "What is the new employee's name" << std::endl;
    std::cin >> name;

    std::cout << "What level is " << name << " getting hired at" << std::endl;
    level = getEmployeeLevel();

    // The level the new employee is hired at determines what list they are inserted into
    switch (level)
    {
        case 0:
            if ((L.hire(name, level)) && (C.hire(name, level)))
            {
                std::cout << name << " was successfully hired as a candidate" << std::endl;
                return;
            }
            else
            {
                std::cout << "Hiring of " << name << " failed" << std::endl;
            }
            break;
        case 1:
            if ((L.hire(name, level)) && (D.hire(name, level)))
            {
                std::cout << name << " was successfully hired as a developer" << std::endl;
                return;
            }
            else
            {
                std::cout << "Hiring of " << name << " failed" << std::endl;
            }
            break;
        case 2:
            if ((L.hire(name, level)) && (TL.hire(name, level)))
            {
                std::cout << name << " was successfully hired as a team lead" << std::endl;
                return;
            }
            else
            {
                std::cout << "Hiring of " << name << " failed" << std::endl;
            }
            break;
        case 3:
            if ((L.hire(name, level)) && (PL.hire(name, level)))
            {
                std::cout << name << " was successfully hired as a project lead" << std::endl;
                return;
            }
            else
            {
                std::cout << "Hiring of " << name << " failed" << std::endl;
            }
            break;
    }

}

void printLevel(ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C)
{

    std::cout << "What level would you like to print?" << std::endl;
    int level = getEmployeeLevel();

    switch (level)
    {
        case 0:
            C.printA();
            break;
        case 1:
            D.printA();
            break;
        case 2:
            TL.printA();
            break;
        case 3:
            PL.printA();
            break;
    }
}

void getEmployeeInfo(ListOfEmployees &L)
{
    std::string name;
    int level;

    std::cout << "What is the employee's name you would like information from?" << std::endl;
    std::cin >> name;

    level = L.getEmployeeLevel(name);

    if (level == -1)
    {
        std::cout << "No employee with the name " << name << " is currently employed" << std::endl;
        return;
    }

    std::cout << "\nInformation on " << name << ":" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Mentorship status: ";
    L.getMentorshipInfo(name);

}

void changeEmployeeLevel(ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C)
{
    std::string name;
    int newLevel;
    int currantLevel;

    std::cout << "What is the employee's name" << std::endl;
    std::cin >> name;

    currantLevel = L.getEmployeeLevel(name);

    if (currantLevel == -1)
    {
        std::cout << "No employee with the name " << name << " is currently employed" << std::endl;
        return;
    }

    std::cout << "What is the new level of " << name << std::endl;
    newLevel = getEmployeeLevel();

    // Removes employee from currant level list
    switch (currantLevel)
    {
        case 0:
            if (!C.fire(name))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 1:
            if (!D.fire(name))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 2:
            if (!TL.fire(name))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 3:
            if (!PL.fire(name))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
    }

    // Inserts employee into new level list
    switch (newLevel)
    {
        case 0:
            if (!C.hire(name,newLevel))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 1:
            if (!D.hire(name, newLevel))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 2:
            if (!TL.hire(name, newLevel))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
        case 3:
            if (!PL.hire(name, newLevel))
            {
                std::cout << name << "'s level was not able to be changed" << std::endl;
                return;
            }
            break;
    }

    // Change level of employee in master list.
    if(L.changeLevel(name, newLevel))
    {
        std::cout << name << "'s level was successfully changed" << std::endl;
    }
    // If employee doesn't exist, the getEmployeeLevel will catch that error, but just in case.
    else
    {
        std::cout << name << "'s level was not able to be changed" << std::endl;
    }

}

void terminateEmployee(ListOfEmployees &L, ListOfLevel &PL, ListOfLevel &TL, ListOfLevel &D, ListOfLevel &C)
{
    std::string name;
    int level;

    std::cout << "What is the employee to be terminated's name?" << std::endl;
    std::cin >> name;

    level = L.getEmployeeLevel(name);

    if (level == -1)
    {
         std::cerr << "No employee with the name " << name << " is currently employed" << std::endl;
         return;
    }

    // Removes employee from master list and level list
    switch (level)
    {
    case 0:
        if ((L.fire(name)) && (C.fire(name)))
        {
            std::cout << name << " was successfully terminated" << std::endl;
            return;
        }
        else
        {
            std::cout << name << " was not able to be terminated" << std::endl;
        }
        break;
    case 1:
        if ((L.fire(name)) && (D.fire(name)))
        {
            std::cout << name << " was successfully terminated" << std::endl;
            return;
        }
        else
        {
            std::cout << name << " was not able to be terminated" << std::endl;
        }
        break;
    case 2:
        if ((L.fire(name)) && (TL.fire(name)))
        {
            std::cout <<  name << " was successfully terminated" << std::endl;
            return;
        }
        else
        {
            std::cout << name << " was not able to be terminated" << std::endl;
        }
        break;
    case 3:
        if ((L.fire(name)) && (PL.fire(name)))
        {
            std::cout <<  name << " was successfully terminated" << std::endl;
            return;
        }
        else
        {
            std::cout << name << " was not able to be terminated" << std::endl;
        }
        break;
    }
}

void createNewMentorship (ListOfEmployees &L)
{
    std::string mentor;
    std::string mentee;

    std::cout << "What is the name of the mentor" << std::endl;
    std::cin >> mentor;

    std::cout << "What is the name of the mentee" << std::endl;
    std::cin >> mentee;

    if (L.createMentorship(mentor, mentee))
    {
        std::cout << "Mentorship successfully created" << std::endl;
    }
    else
    {
        std::cout << "Mentorship was not created" << std::endl;
    }
}

void endMentorship(ListOfEmployees &L)
{
    std::string mentor;
    std::string mentee;

    std::cout << "What is the name of the mentor in the mentorship that is to be ended?" << std::endl;
    std::cin >> mentor;

    std::cout << "What is the name of the mentee in the mentorship that is to be ended?" << std::endl;
    std::cin >> mentee;


    if (L.endMentorship(mentor, mentee))
    {
        std::cout << "Mentorship successfully ended" << std::endl;
    }
    else
    {
        std::cout << "Mentorship could not be ended" << std::endl;
    }
    
}

void getMentorshipInfo(ListOfEmployees &L)
{
    std::string name;

    std::cout << "What is the name of the employee to get mentorship information from" << std::endl;
    std::cin >> name;

    L.getMentorshipInfo(name);
}

int getEmployeeLevel()
{

    int level;
    bool quit = false;

    do {
        std::cout << "\n0 for candidate\n1 for developer\n2 for team lead\n3 for project lead" << std::endl;
        std::cin >> level;
        if (std::cin.fail() || (level < 0) || (level > 3)) 
        {
            std::cin.clear();
            std::cin.ignore(numCharsToDisgardCinIgnore, '\n');
            std::cerr << "Error: Invalid employee level" << std::endl;
        } 
        else 
        {
            quit = true;
        }
    } while (!quit);

    return(level);
} 


int main()
{
    // Master list of all employees
    ListOfEmployees L;

    // Project lead employees list
    ListOfLevel PL;
    // Team lead employees list
    ListOfLevel TL;
    // Developer employees list
    ListOfLevel D;
    // Candidate employees list
    ListOfLevel C;

    char cmd;
    bool done = false;

    printMenu();

    do{

        std::cout << "\nWhat would you like to do? (one of ITGCPANEBJQ H for Help)" << std::endl;
        std::cin >> cmd;
        cmd = toupper(cmd);

        switch (cmd)
        {
            case 'I':
                hireNewEmployee(L, PL, TL, D, C);
                break;
            case 'P':
                printLevel(PL, TL, D, C);
                break;
            case 'A':
                L.printA();
                break;
            case 'H':
                printMenu();
                break;
            case 'G':
                getEmployeeInfo(L);
                break;
            case 'T':
                terminateEmployee(L, PL, TL, D, C);
                break;
            case 'N':
                createNewMentorship(L);
                break;
            case 'E':
                endMentorship(L);
                break;
            case 'J':
                getMentorshipInfo(L);
                break;
            case 'B':
                L.printAllMentorships();
                break;
            case 'C':
                changeEmployeeLevel(L, PL, TL, D, C);
                break;
            case 'Q':
                std::cout << "Bye!" << std::endl;
                done = true;
                break;
            default:
                std::cin.clear();
                std::cin.ignore(numCharsToDisgardCinIgnore, '\n');
                std::cerr << "Error: Invalid choice of input" << std::endl;
        }
        
    }while (!done);
    
    return 0;
}
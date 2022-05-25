#include "lists.h"
#include <iostream>

// Master list constructor
ListOfEmployees::ListOfEmployees () {

    front = NULL;
    back = NULL;
    size = 0;
}

// Master list destructor
ListOfEmployees::~ListOfEmployees () {

    deallocate();
}

// Private:
// Deletes each node from a list until empty.
// Called by destructor.
void ListOfEmployees::deallocate()
{
    employee * currant = front;
    employee * toDelete;

    while (currant != NULL)
    {
        toDelete = currant;
        currant = currant->next;
        delete toDelete;
    }
}
// Public: 
// Calls the private create method and passes it the new employee's name and level.
// If new employee node was created succsessfully
//  Calls private instert method, passing the new employee node.
bool ListOfEmployees::hire (std::string name, int level){

    employee * newE = create(name, level);

    if (newE == NULL)
    {
        return false;
    }

    if (insert(newE))
    {
        return true;
    }

    return false;
}

// Public:
// Calls private lookup method, passing the provided employee name.
// If the employee was found
//  private remove method is called, passing the to be deleted employee node.
bool ListOfEmployees::fire (std::string name){

    employee * toDelete = lookup(name);

    if (toDelete == NULL)
    {
        return false;
    }

    remove(toDelete);

    return true;
}

// Private: 
// Creates a new instance of a employee node and returns it.
// Returns NULL if unsuccessful. 
ListOfEmployees::employee * ListOfEmployees::create (std::string name, int level)
{

    employee * newE = new employee;

    if (newE != NULL)
    {
        newE->name = name;
        newE->level = level;
        newE->next = NULL;
        newE->prev = NULL;
        newE->mentee = NULL;
        newE->mentor = NULL;

        return newE;
    }

    return NULL;
}

// Private:
// Inserts new employee into the back of the list and increments size.
// Always returns true.
bool ListOfEmployees::insert(employee * newE)
{
    if (front == NULL)
    {
        front = newE;
        back = newE;
        size++;
        return true;
    }
    else
    {
        back->next = newE;
        newE->prev = back;
        newE->next = NULL;
        back = newE;
        size++;
        return true;
    }
}

// Private:
// Removes employee from list and resets mentorship pointers and increments size. 
// Always returns true.
bool ListOfEmployees::remove(employee * toDelete)
{

    // Remove mentorship information of employee before they are deleted
    if (toDelete->mentee != NULL)
    {
        toDelete->mentee->mentor = NULL;
        toDelete->mentee = NULL;
    }
    
    
    if (toDelete->mentor != NULL)
    {
        toDelete->mentor->mentee = NULL;
        toDelete->mentor = NULL;
    }

    // If there is only one employee in the list
    if ((toDelete->next == NULL) && (toDelete->prev == NULL))
    {
        front = NULL;
        back = NULL;
        size = 0;
        delete toDelete;
        return true;
    }
    // If the employee to delete is in the back of the list
    else if (toDelete->next == NULL)
    {
        back = toDelete->prev;
        back->next = NULL;
    } 
    // If the employee to delete is in the front of the list
    else if (toDelete->prev == NULL)
    {
        front = toDelete->next;
        front->prev = NULL;
    }
    // If the employee to delete is somewhere in the middle
    else
    {
        employee * before = toDelete->prev;
        employee * after = toDelete->next;
        before->next = after;
        after->prev = before;
    }

    delete toDelete;
    size--;
    return true;

}

// Public:
// Calls private printAll
void ListOfEmployees::printA()
{
    printAll();
}

// Private:
// Prints all employee's name and level.
void ListOfEmployees::printAll()
{
    if (size == 0){

        std::cout << "There are no employees currently hired" << std::endl;
        return;
    }
    std::cout << "\nList of all " << size << " employees: " << std::endl;

    employee * currant = front;

    while(currant != NULL)
    {

        std::cout << "Name: " << currant->name << "\nPosition: " << currant->level << "\n" << std::endl;

        currant = currant->next;
    }
}

// Public:
// Retruns the level of a given employee
int ListOfEmployees::getEmployeeLevel(std::string name)
{

    employee * e = lookup(name);

    if (e == NULL)
    {
        return -1;
    }

    return e->level;


}

// Private: 
// Searches list for an employee by name, returns pointer to employee if found.
// Returns NULL if no employee was found.
ListOfEmployees::employee * ListOfEmployees::lookup (std::string n)
{
    employee * currant = front;

    while(currant != NULL)
    {
        if (currant->name == n)
        {
            return currant;
        }
        currant = currant->next;
    }

    return NULL;
}

// Public: 
// Changes the integer value of the level of a given employee, 
bool ListOfEmployees::changeLevel(std::string name, int newLevel)
{
    employee * e = lookup(name);

    if (e == NULL)
    {
        return false;
    }

    e->level = newLevel;
    
    return true;
}

// Public:
// Calls private lookup method on both the mentor and mentee
// If both are currant employees
//  Checks to see if mentor is a higher level than the mentee, If not returns false.
//  Checks to see if mentor already has a mentee or mentee already has a mentor.
//    If so calls confirmMentorship to confirm user wants to overwrite existing mentorship.
// If all is correct, calls private initializeMentorship method, passing the mentor node and mentee node.
// Returns true if initializeMentorship returned true.
bool ListOfEmployees::createMentorship(std::string mentor, std::string mentee)
{
    employee * mtor = lookup(mentor);

    employee * mtee = lookup(mentee);

    if (mtee == NULL)
    {
        std::cerr << "No employee with the name " << mentee << " is currently employed" << std::endl;
        return false;
    }

    if (mtor == NULL)
    {
        std::cerr << "No employee with the name " << mentor << " is currently employed" << std::endl;
        return false;
    }

    if (mtor->level <= mtee->level)
    {
        std::cerr << "Mentee can not be a higher or same level as their mentor" << std::endl;
        return false;
    }

    // If the mentor already has a mentee
    if (mtor->mentee != NULL)
    {

        // If the mentor and mentee are already in a mentorship
        if (mtor->mentee->name == mentee)
        {
            std::cerr << mentor << " and " << mentee << " are already in a mentorship" << std::endl;
            return false;
        }

        if (!confirmMentorship(mtor))
        {
            return false;
        }
    }

    // If mentee already has a mentor
    if (mtee->mentor != NULL)
    {
        if (!confirmMentorship(mtee))
        {
            return false;
        }
    }


    if (initializeMentorship(mtor, mtee))
    {
        return true;
    }

    return false;

}

// Friend Function:
// Called if user is wanting to create a new mentorship with an employee that is already involved in a mentorship.
// Asks user if they are sure they would like to overwite the exiting senatorship.
// Returns true or false based on users responce. 
bool confirmMentorship (ListOfEmployees::employee * e)
{
    char confirmation;
    bool error;

    do
    {
        error = false;
        std::cout << e->name << " is currently invloved in a mentorship\nAre you sure you want to overwrite this mentorship (y or n)" << std::endl;
        std::cin >> confirmation;
        confirmation = toupper(confirmation);

        if (confirmation == 'Y')
        {
            return true;
        }
        else if (confirmation == 'N')
        {
            std::cout << "Mentorship was cancled" << std::endl;
            return false;
        }
        else
        {   
            std::cin.clear();
            std::cin.ignore(numCharsToDisgardCinIgnore, '\n');
            std::cerr << "Error: Invalid choice of input" << std::endl;
            error = true;
        }
    }while(error);

    return false;
}

// Public:
// Calls private lookup method on both the mentor and mentee
// If both are currant employs
//  Calls private removeMentorship method, passing the mentor node and mentee node.
// Returns true if removeMentorship returned true.
bool ListOfEmployees::endMentorship(std::string mentor, std::string mentee)
{
    employee * mtor = lookup(mentor);

    employee * mtee = lookup(mentee);

    if (mtee == NULL)
    {
        std::cerr << "No employee with the name " << mentee << " is currently employed" << std::endl;
        return false;
    }

    if (mtor == NULL)
    {
        std::cerr << "No employee with the name " << mentor << " is currently employed" << std::endl;
        return false;
    }

    if (removeMentorship(mtor, mtee))
    {
        return true;
    }

    return false;

}

// Private:
// If somehow the mentor and mentee are not in a mentorship, returns false
// Else sets mentorship pointers to NULL
bool ListOfEmployees::removeMentorship(employee * mentor, employee * mentee)
{
    if (mentor->mentee != mentee) 
    {
        std::cerr << "Error: Given employees are not currently in a mentorship" << std::endl;
        return false;
    }

    mentor->mentee = NULL;
    mentee->mentor = NULL;

    return true;
}

// Private: 
// If mentorship already exist, remove pointers to previous mentor/mentee
// Sets mentorship pointers to point to eachother 
bool ListOfEmployees::initializeMentorship(employee * mentor, employee * mentee)
{
    if (mentor->mentee != NULL)
    {
        mentor->mentee->mentor = NULL;
    }

    if (mentee->mentor != NULL)
    {
        mentee->mentor->mentee = NULL;
    }

    mentor->mentee = mentee;

    mentee->mentor = mentor;

    return true;

}

// Public:
// Calls private lookup method on the provided name
// If employee is found, calls private mentorshipInfo mehtod, passing the employee node.
void ListOfEmployees::getMentorshipInfo(std::string name)
{
    employee * e = lookup(name);

    if (e == NULL)
    {
        std::cerr << "No employee with the name " << name << " is currently hired" << std::endl;
        return;
    }

   mentorshipInfo(e);

}

// Private: 
// Prints mentorship info of a given employee
void ListOfEmployees::mentorshipInfo(employee * e)
{
    if ((e->mentee == NULL) && (e->mentor == NULL))
    {
        std::cout << e->name << " is not currently involved in a mentorship" << std::endl;
        return;
    }

    if (e->mentee != NULL)
    {
        std::cout << e->name << " is currently a mentor of " << e->mentee->name << std::endl;
    }

    if (e->mentor != NULL)
    {
        std::cout << e->name << " is currently a mentee of " << e->mentor->name << std::endl;
    }

}


// Public: 
// prints out all of the currant mentorship pairs
void ListOfEmployees::printAllMentorships()
{
    if (size == 0){

    std::cout << "There are no employees currently hired" << std::endl;
    return;
    }

    employee * currant = front;

    std::cout << "List of all currant mentorships: " << std::endl;

    while(currant != NULL)
    {
        if (currant->mentee != NULL)
        {
            std::cout << "Name of mentor: " << currant->name << "  <---->  Name of mentee: " << currant->mentee->name << "\n" << std::endl;
        }
        currant = currant->next;
    }

}

// ListOfLevels
// -----------------------------------------------------------------------------------------------------------------

// Level list constructor
ListOfLevel::ListOfLevel () {

    front = NULL;
    back = NULL;
    size = 0;
}

// Level list destructor
ListOfLevel::~ListOfLevel () {

    deallocate();
}

// Private:
// Same as master list deallocate
void ListOfLevel::deallocate()
{
    employee * currant = front;
    employee * toDelete;

    while (currant != NULL)
    {
        toDelete = currant;
        currant = currant->next;
        delete toDelete;
    }
}

// Private:
// Same as master list create
ListOfLevel::employee * ListOfLevel::create (std::string name, int level)
{

    employee * newE = new employee;

    if (newE != NULL)
    {
        newE->name = name;
        newE->level = level;
        newE->next = NULL;
        newE->prev = NULL;

        return newE;
    }

    return NULL;
}

// Public:
// Same as master list hire
bool ListOfLevel::hire (std::string name, int level){

    employee * newE = create(name, level);

    if (newE == NULL)
    {
        return false;
    }

    if (insert(newE))
    {
        return true;
    }

    return false;
}

// Private:
// Same as master list insert
bool ListOfLevel::insert(employee * newE)
{
    if (front == NULL)
    {
        front = newE;
        back = newE;
        size++;
        return true;
    }
    else
    {
        back->next = newE;
        newE->prev = back;
        newE->next = NULL;
        back = newE;
        size++;
        return true;
    }

}

// Public:
// Same as master list fire
bool ListOfLevel::fire (std::string name){

    employee * toDelete = lookup(name);

    if (toDelete == NULL)
    {
        return false;
    }

    remove(toDelete);

    return true;
}

// Private:
// Same as master list remove
bool ListOfLevel::remove(employee * toDelete)
{

    // If there is only one employee in the list
    if ((toDelete->next == NULL) && (toDelete->prev == NULL))
    {
        front = NULL;
        back = NULL;
        size = 0;
        delete toDelete;
        return true;
    }
    // If the employee to delete is in the back of the list
    else if (toDelete->next == NULL)
    {
        back = toDelete->prev;
        back->next = NULL;
    } 
    // If the employee to delete is in the front of the list
    else if (toDelete->prev == NULL)
    {
        front = toDelete->next;
        front->prev = NULL;
    }
    // If the employee to delete is somewhere in the middle
    else
    {
        employee * before = toDelete->prev;
        employee * after = toDelete->next;
        before->next = after;
        after->prev = before;
    }

    delete toDelete;
    size--;
    return true;

}

// Private:
// Same as master list lookup
ListOfLevel::employee * ListOfLevel::lookup (std::string n)
{
    employee * currant = front;

    while(currant != NULL)
    {
        if (currant->name == n)
        {
            return currant;
        }
        currant = currant->next;
    }

    return NULL;
}

// Public:
// Same as master list PrintA
void ListOfLevel::printA()
{
    printAll();
}

// Private:
// Same as master list PrintAll
void ListOfLevel::printAll()
{
    if (size == 0){

        std::cout << "There are no employees currently hired at this level" << std::endl;
        return;
    }

    employee * currant = front;

        std::cout << "\nList of all " << size << " employees in level " << currant->level << std::endl;

    while(currant != NULL)
    {

        std::cout << "Name: " << currant->name << "\nPosition: " << currant->level << "\n" << std::endl;

        currant = currant->next;
    }
}


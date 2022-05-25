Jasper Charlinski

NOTES
---------------------------------------------------------------------------------
In hindsight I should have used inheritance to make the ListOfEmployees a child of the ListOfLevel class, 
and if I were to restart this project from scratch that is what I would do. 

Each employee has a node in both the master list, containing all of the employees, and their level's list, 
containing all of the employees at a given level.
When employees are hired/fired both lists are altered.

For mentorships, a mentor must be at a higher level than their mentee. I choses to make this a rule because
it makes sense to me that an employee would not want to be mentored be a co-worker at a lower or same level.

---------------------------------------------------------------------------------
HOW TO RUN PROGRAM
---------------------------------------------------------------------------------

Make sure you are in the directory containing the list.cpp, list.h, project.cpp, project.h, and make files

How to compile: 

    make

    ./projectx

---------------------------------------------------------------------------------
ERRORS / BUGS
---------------------------------------------------------------------------------

Program runs as the documentation suggests with no noticeable error.

Bugs:

An employee that is a mentee can be promoted to a level above their mentor without error,
I figured this was not a problem since a newly promoted employee could still be learning from their mentor.
Also I assumed in the real world the workplace would end the mentorship before promoting the employee.

Not necessarily a bug, but it is important to note an employee can only have one mentor and one mentee at a time.

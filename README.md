GIT repository for csci161-030506/project

Jasper Charlinski
658366479

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
EXAMPLE RUN
---------------------------------------------------------------------------------

H: Print help menu
I: Insert a new employee
T: Terminate an employee
G: Get an employee's information
C: Change an employee's level
P: Print all employees of a level
A: Print all employees
N: Create a new mentorship pair
E: End mentorship
B: Print all currant mentorships
J: Get mentorship information of an employee
Q: Quit

What would you like to do? (one of ITJCPANEBGQ H for Help)
i
What is the new employee's name
Jasper
What level is Jasper getting hired at

0 for candidate
1 for developer
2 for team lead
3 for project lead
3
Jasper was successfully hired as a project lead

What would you like to do? (one of ITJCPANEBGQ H for Help)
i
What is the new employee's name
Bob
What level is Bob getting hired at

0 for candidate
1 for developer
2 for team lead
3 for project lead
2
Bob was successfully hired as a team lead

What would you like to do? (one of ITJCPANEBGQ H for Help)
i
What is the new employee's name
Foo
What level is Foo getting hired at

0 for candidate
1 for developer
2 for team lead
3 for project lead
0
Foo was successfully hired as a candidate

What would you like to do? (one of ITJCPANEBGQ H for Help)
a

List of all 3 employees: 
Name: Jasper
Position: 3

Name: Bob
Position: 2

Name: Foo
Position: 0


What would you like to do? (one of ITJCPANEBGQ H for Help)
p
What level would you like to print?

0 for candidate
1 for developer
2 for team lead
3 for project lead
3

List of all 1 employees in level 3
Name: Jasper
Position: 3


What would you like to do? (one of ITJCPANEBGQ H for Help)
n
What is the name of the mentor
Jasper
What is the name of the mentee
Foo
Mentorship successfully created

What would you like to do? (one of ITJCPANEBGQ H for Help)
b
List of all currant mentorships: 
Name of mentor: Jasper  <---->  Name of mentee: Foo


What would you like to do? (one of ITJCPANEBGQ H for Help)
g
What is the employee's name you would like information from?
Jasper

Information on Jasper:
Name: Jasper
Level: 3
Mentorship status: Jasper is currently a mentor of Foo

What would you like to do? (one of ITJCPANEBGQ H for Help)
n
What is the name of the mentor
Jasper
What is the name of the mentee
Bob
Jasper is currently a mentor of Foo
Are you sure you want to overwrite this mentorship (y or n)
y
Mentorship successfully created

What would you like to do? (one of ITJCPANEBGQ H for Help)
b
List of all currant mentorships: 
Name of mentor: Jasper  <---->  Name of mentee: Bob


What would you like to do? (one of ITJCPANEBGQ H for Help)
g
What is the employee's name you would like information from?
Jasper

Information on Jasper:
Name: Jasper
Level: 3
Mentorship status: Jasper is currently a mentor of Bob

What would you like to do? (one of ITJCPANEBGQ H for Help)
e
What is the name of the mentor in the mentorship that is to be ended?
Jasper
What is the name of the mentee in the mentorship that is to be ended?
Bob
Mentorship successfully ended

What would you like to do? (one of ITJCPANEBGQ H for Help)
b
List of all currant mentorships: 

What would you like to do? (one of ITJCPANEBGQ H for Help)
g
What is the employee's name you would like information from?
Jasper

Information on Jasper:
Name: Jasper
Level: 3
Mentorship status: Jasper is not currently involved in a mentorship

What would you like to do? (one of ITJCPANEBGQ H for Help)
c
What is the employee's name
Jasper
What is the new level of Jasper

0 for candidate
1 for developer
2 for team lead
3 for project lead
0
Jasper's level was successfully changed

What would you like to do? (one of ITJCPANEBGQ H for Help)
p
What level would you like to print?

0 for candidate
1 for developer
2 for team lead
3 for project lead
0

List of all 2 employees in level 0
Name: Foo
Position: 0

Name: Jasper
Position: 0


What would you like to do? (one of ITJCPANEBGQ H for Help)
n
What is the name of the mentor
Jasper
What is the name of the mentee
Bob
Mentee can not be a higher level than their mentor
Mentorship was not created

What would you like to do? (one of ITJCPANEBGQ H for Help)
t
What is the employee to be terminated's name?
Jasper
Jasper was successfully terminated

What would you like to do? (one of ITJCPANEBGQ H for Help)
a

List of all 2 employees: 
Name: Bob
Position: 2

Name: Foo
Position: 0


What would you like to do? (one of ITJCPANEBGQ H for Help)
t
What is the employee to be terminated's name?
Foo
Foo was successfully terminated

What would you like to do? (one of ITJCPANEBGQ H for Help)
t
What is the employee to be terminated's name?
Bob
Bob was successfully terminated

What would you like to do? (one of ITJCPANEBGQ H for Help)
a
There are no employees currently hired

What would you like to do? (one of ITJCPANEBGQ H for Help)
p
What level would you like to print?

0 for candidate
1 for developer
2 for team lead
3 for project lead
3
There are no employees currently hired at this level

What would you like to do? (one of ITJCPANEBGQ H for Help)
q
Bye!

---------------------------------------------------------------------------------
ERRORS / BUGS
---------------------------------------------------------------------------------

Program runs as the documentation suggests with no noticeable error.

Bugs:

An employee that is a mentee can be promoted to a level above their mentor without error,
I figured this was not a problem since a newly promoted employee could still be learning from their mentor.
Also I assumed in the real world the workplace would end the mentorship before promoting the employee.

Not necessarily a bug, but it is important to note an employee can only have one mentor and one mentee at a time.
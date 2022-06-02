<p>Jasper Charlinski</p>
<p>April 8th, 2022</p>

<br />

<h3>About: </h3>
<p>An employee management program where data nodes for each employee are stored in a linked list. Employees can be hired to one of 4 levels at the company, promoted or demoted between levels, and terminated from the company. Employees can also participate in mentorship programs with other employees if the requirements are met. </p>
<p>This was my final project submission for CSCI161 at Vancouver Island University</p>

<br />

<h3>Notes</h3>

<p>In hindsight I should have used inheritance to make the ListOfEmployees a child of the ListOfLevel class, 
and if I were to restart this project from scratch that is what I would do. </p>


<p>Each employee has a node in both the master list, containing all of the employees, and their level's list, 
containing all of the employees at a given level. When employees are hired/fired both lists are altered.</p>

<p>For mentorships, a mentor must be at a higher level than their mentee. I chose to make this a rule because
it makes sense to me that an employee would not want to by mentored be a co-worker at a lower or same level.</p>

<br />

<h3>How to run</h3>
<p>Note: You must have a C++ compiler installed on your computer.</p>

    make

    ./projectx
    
<br />

<h3>Bugs: </h3>

<p>Program runs as the documentation suggests with no noticeable error.</p>

<h4>Bugs</h4>

<p>An employee that is a mentee can be promoted to a level above their mentor without error,
I figured this was not a problem since a newly promoted employee could still be learning from their mentor.
Also I assumed in the real world the workplace would end the mentorship before promoting the employee.</p>

<p>Not necessarily a bug, but it is important to note an employee can only have one mentor and one mentee at a time.</p>

<br />

<p>This assignment was created by Dr. David Wessels of Vancouver Island University.</p>

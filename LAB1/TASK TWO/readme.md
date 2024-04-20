Struct Definitions:

Grade: Represents student grades, including members for the numerical mark and the corresponding letter grade.
Course: Represents course details, storing the course code and name.
Student: Central structure containing information such as registration number, name, age, course, grades, and a flag indicating whether grades have been calculated.
Function Prototypes:

setGrades: Updates a student's grades based on a given mark.
addStudent: Adds a new student to the system, considering a maximum limit.
editStudent: Allows the user to modify the details of an existing student.
addMarks: Enables the user to input marks for a student and calculates the corresponding grades, ensuring grades are not altered once computed.
displayMenu: Presents menu options to the user.
Main Function:

Declares an array of students with a maximum capacity of 40.
Utilizes a loop to display the menu and process user input until an exit choice is made.
Calls different functions based on user selections, including adding students, editing details, adding marks, or exiting the program.
Other Functions:

setGrades: Takes a Grade structure and a mark as input, setting the mark and calculating the corresponding grade.
addStudent: Takes the array of students and the number of students as input, adding a new student if the limit is not reached.
editStudent: Takes the array of students and the number of students as input, allowing the user to edit the details of an existing student.
addMarks: Takes the array of students and the number of students as input, letting the user add marks and calculates grades for a specific student.
displayMenu: Prints the menu options for the user to choose from.
In summary, the program effectively manages student data, provides a user-friendly interface, and ensures the integrity of grades once calculated
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 40

// Grade structure definition
struct Grade {
    int mark;
    char the_grade;
};

// Course structure definition
struct Course {
    char course_code[10];
    char course_name[50];
};

// Student structure definition
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    Course course;
    Grade grades;
    int grades_calculated; // 0 for false, 1 for true
};

// Function prototypes
void setGrades(Grade *grades, int mark);
void addStudent(Student *students, int *numStudents);
void editStudent(Student *students, int numStudents);
void addMarks(Student *students, int numStudents);
void displayMenu();

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addStudent(students, &numStudents);
                break;
            case '2':
                editStudent(students, numStudents);
                break;
            case '3':
                addMarks(students, numStudents);
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}

// Function to set or update grades
void setGrades(Grade *grades, int mark) {
    grades->mark = mark;

    if (mark > 69)
        grades->the_grade = 'A';
    else if (mark > 59)
        grades->the_grade = 'B';
    else if (mark > 49)
        grades->the_grade = 'C';
    else if (mark > 39)
        grades->the_grade = 'D';
    else
        grades->the_grade = 'E';
}

// Function to add a student
void addStudent(Student *students, int *numStudents) {
    if (*numStudents < MAX_STUDENTS) {
        Student newStudent;
        printf("Enter registration number: ");
        scanf("%s", newStudent.reg_number);
        printf("Enter name: ");
        scanf("%s", newStudent.name);
        printf("Enter age: ");
        scanf("%d", &newStudent.age);
        printf("Enter course code: ");
        scanf("%s", newStudent.course.course_code);
        printf("Enter course name: ");
        scanf("%s", newStudent.course.course_name);
        newStudent.grades_calculated = 0;

        students[*numStudents] = newStudent;
        (*numStudents)++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to edit a student's details
void editStudent(Student *students, int numStudents) {
    char reg[20];
    printf("Enter registration number to edit: ");
    scanf("%s", reg);

    int found = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(students[i].reg_number, reg) == 0) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Student details updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to add marks and calculate grades
void addMarks(Student *students, int numStudents) {
    char reg[20];
    printf("Enter registration number to add marks: ");
    scanf("%s", reg);

    int found = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (strcmp(students[i].reg_number, reg) == 0) {
            if (students[i].grades_calculated) {
                printf("Grades already calculated and cannot be altered.\n");
            } else {
                int mark;
                printf("Enter marks for %s: ", students[i].name);
                scanf("%d", &mark);
                setGrades(&students[i].grades, mark);
                students[i].grades_calculated = 1;
                printf("Grades calculated and set successfully.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to display menu
void displayMenu() {
    printf("MENU:\n");
    printf("1. Add Student\n");
    printf("2. Edit Student\n");
    printf("3. Add Marks and Calculate Grades\n");
    printf("4. Exit\n");
}



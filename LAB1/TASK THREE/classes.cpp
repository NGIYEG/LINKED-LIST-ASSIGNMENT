#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// Grade class definition
class Grade {
public:
    int mark;
    char the_grade;

    Grade(int mark) : mark(mark) {
        calculateGrade();
    }

private:
    void calculateGrade() {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }                               
};

// Course class definition
class Course {
public:
    std::string course_code;
    std::string course_name;

    Course(const std::string& code, const std::string& name) : course_code(code), course_name(name) {}
};

// Student class definition
class Student {
public:
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;

    // Constructor
    Student(const std::string& reg, const std::string& n, int a, const Course& c)
        : reg_number(reg), name(n), age(a), course(c), grades(0), grades_calculated(false) {}

    // Function to set or update grades
    void setGrades(int mark) {
        if (!grades_calculated) {
            grades = Grade(mark);
            grades_calculated = true;
        } else {
            std::cout << "Grades already calculated and cannot be altered." << std::endl;
        }
    }
};

// Class to manage the students
class StudentManager {
public:
    void addStudent(const Student& s) {
        if (students.size() < MAX_STUDENTS) {
            students.push_back(s);
            std::cout << "Student added successfully." << std::endl;
        } else {
            std::cout << "Maximum number of students reached." << std::endl;
        }
    }

    void editStudentDetails(const std::string& reg, const std::string& newName, int newAge) {
        for (auto& student : students) {
            if (student.reg_number == reg) {
                student.name = newName;
                student.age = newAge;
                std::cout << "Student details updated successfully." << std::endl;
                return;
            }
        }
        std::cout << "Student not found." << std::endl;
    }

    void addMarksAndCalculateGrades(const std::string& reg, int mark) {
        for (auto& student : students) {
            if (student.reg_number == reg) {
                student.setGrades(mark);
                std::cout << "Grades calculated and set successfully." << std::endl;
                return;
            }
        }
        std::cout << "Student not found." << std::endl;
    }

private:
    static const int MAX_STUDENTS = 40;
    std::vector<Student> students;
};

int main() {
    StudentManager studentManager;

    Course computerScience("CS101", "Introduction to Computer Science");
    studentManager.addStudent(Student("12345", "John Doe", 20, computerScience));
    studentManager.editStudentDetails("12345", "John Smith", 21);
    studentManager.addMarksAndCalculateGrades("12345", 75);

    return 0;
}

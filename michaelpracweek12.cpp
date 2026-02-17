#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

// Forward declarations
class Course;
class Instructor;
class Student;

// Student Class
class Student {
private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    string major;
    vector<Course*> enrolledCourses; // Association: Student HAS-A list of Courses

public:
    Student(string studentId, string firstName, string lastName, string email, string major) {
        this->studentId = studentId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->major = major;
    }

    string getStudentId() {
        return studentId;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getFullName() {
        return firstName + " " + lastName;
    }

    string getEmail() {
        return email;
    }

    string getMajor() {
        return major;
    }

    vector<Course*> getEnrolledCourses() {
        return enrolledCourses;
    }

    void enrollInCourse(Course* course) {
        if (find(enrolledCourses.begin(), enrolledCourses.end(), course) == enrolledCourses.end()) {
            enrolledCourses.push_back(course);
        }
    }

    void dropCourse(Course* course) {
        enrolledCourses.erase(remove(enrolledCourses.begin(), enrolledCourses.end(), course), enrolledCourses.end());
    }

    void displayInfo() {
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << getFullName() << endl;
        cout << "Email: " << email << endl;
        cout << "Major: " << major << endl;
        cout << "Enrolled Courses: " << enrolledCourses.size() << endl;
    }
};

// Course Class
class Course {
private:
    string courseCode;
    string courseName;
    int credits;
    Instructor* instructor; // Association: Course HAS-A Instructor
    int maxCapacity;
    vector<Student*> enrolledStudents; // Association: Course HAS-A list of Students

public:
    Course(string courseCode, string courseName, int credits, int maxCapacity) {
        this->courseCode = courseCode;
        this->courseName = courseName;
        this->credits = credits;
        this->maxCapacity = maxCapacity;
        this->instructor = nullptr;
    }

    string getCourseCode() {
        return courseCode;
    }

    string getCourseName() {
        return courseName;
    }

    int getCredits() {
        return credits;
    }

    Instructor* getInstructor() {
        return instructor;
    }

    void setInstructor(Instructor* instructor) {
        this->instructor = instructor;
    }

    int getMaxCapacity() {
        return maxCapacity;
    }

    vector<Student*> getEnrolledStudents() {
        return enrolledStudents;
    }

    bool isFull() {
        return enrolledStudents.size() >= maxCapacity;
    }

    bool addStudent(Student* student) {
        if (!isFull() && find(enrolledStudents.begin(), enrolledStudents.end(), student) == enrolledStudents.end()) {
            enrolledStudents.push_back(student);
            return true;
        }
        return false;
    }

    void removeStudent(Student* student) {
        enrolledStudents.erase(remove(enrolledStudents.begin(), enrolledStudents.end(), student), enrolledStudents.end());
    }

    void displayInfo();
};

// Instructor Class
class Instructor {
private:
    string instructorId;
    string firstName;
    string lastName;
    string email;
    string department;
    vector<Course*> teachingCourses; // Association: Instructor HAS-A list of Courses

public:
    Instructor(string instructorId, string firstName, string lastName, string email, string department) {
        this->instructorId = instructorId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->department = department;
    }

    string getInstructorId() {
        return instructorId;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getFullName() {
        return "Prof. " + firstName + " " + lastName;
    }

    string getEmail() {
        return email;
    }

    string getDepartment() {
        return department;
    }

    vector<Course*> getTeachingCourses() {
        return teachingCourses;
    }

    void assignCourse(Course* course) {
        if (find(teachingCourses.begin(), teachingCourses.end(), course) == teachingCourses.end()) {
            teachingCourses.push_back(course);
            course->setInstructor(this);
        }
    }

    void displayInfo() {
        cout << "Instructor ID: " << instructorId << endl;
        cout << "Name: " << getFullName() << endl;
        cout << "Email: " << email << endl;
        cout << "Department: " << department << endl;
        cout << "Teaching Courses: " << teachingCourses.size() << endl;
    }
};

void Course::displayInfo() {
    cout << "Course Code: " << courseCode << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Credits: " << credits << endl;
    cout << "Instructor: " << (instructor != nullptr ? instructor->getFullName() : "Not Assigned") << endl;
    cout << "Enrolled: " << enrolledStudents.size() << "/" << maxCapacity << endl;
}

// Registration Class - Demonstrates Dependency
// Registration DEPENDS ON Student, Course, and Date classes
class Registration {
private:
    Student* student;
    Course* course;
    time_t registrationDate;
    string status; // "Active", "Dropped", "Completed"

public:
    Registration(Student* student, Course* course) {
        this->student = student;
        this->course = course;
        this->registrationDate = time(0); // Dependency on Date class
        this->status = "Active";
    }

    Student* getStudent() {
        return student;
    }

    Course* getCourse() {
        return course;
    }

    time_t getRegistrationDate() {
        return registrationDate;
    }

    string getStatus() {
        return status;
    }

    void setStatus(string status) {
        this->status = status;
    }

    void displayInfo() {
        tm* ltm = localtime(&registrationDate);
        cout << "Registration Details:" << endl;
        cout << "Student: " << student->getFullName() << " (" << student->getStudentId() << ")" << endl;
        cout << "Course: " << course->getCourseName() << " (" << course->getCourseCode() << ")" << endl;
        cout << "Date: " << setfill('0') << setw(2) << (ltm->tm_mon + 1) << "/" 
             << setw(2) << ltm->tm_mday << "/" << (ltm->tm_year + 1900) << endl;
        cout << "Status: " << status << endl;
    }
};

// RegistrationSystem Class - Main system controller
class RegistrationSystem {
private:
    vector<Student*> students;
    vector<Course*> courses;
    vector<Instructor*> instructors;
    vector<Registration*> registrations;

public:
    RegistrationSystem() {
    }

    // Add entities
    void addStudent(Student* student) {
        students.push_back(student);
        cout << "✓ Student added: " << student->getFullName() << endl;
    }

    void addCourse(Course* course) {
        courses.push_back(course);
        cout << "✓ Course added: " << course->getCourseName() << endl;
    }

    void addInstructor(Instructor* instructor) {
        instructors.push_back(instructor);
        cout << "✓ Instructor added: " << instructor->getFullName() << endl;
    }

    // Register student for course - Demonstrates Dependency
    bool registerStudentForCourse(Student* student, Course* course) {
        if (course->isFull()) {
            cout << "✗ Registration failed: Course is full" << endl;
            return false;
        }

        vector<Course*> enrolled = student->getEnrolledCourses();
        if (find(enrolled.begin(), enrolled.end(), course) != enrolled.end()) {
            cout << "✗ Registration failed: Student already enrolled" << endl;
            return false;
        }

        // Create registration (Dependency)
        Registration* registration = new Registration(student, course);
        registrations.push_back(registration);

        // Update associations
        student->enrollInCourse(course);
        course->addStudent(student);

        cout << "✓ Registration successful: " << student->getFullName() 
             << " enrolled in " << course->getCourseName() << endl;
        return true;
    }

    // Drop course
    void dropCourse(Student* student, Course* course) {
        student->dropCourse(course);
        course->removeStudent(student);

        // Update registration status
        for (Registration* reg : registrations) {
            if (reg->getStudent() == student && reg->getCourse() == course) {
                reg->setStatus("Dropped");
                break;
            }
        }

        cout << "✓ " << student->getFullName() << " dropped " << course->getCourseName() << endl;
    }

    // Display all registrations
    void displayAllRegistrations() {
        cout << "\n=== ALL REGISTRATIONS ===" << endl;
        if (registrations.empty()) {
            cout << "No registrations found." << endl;
        } else {
            for (int i = 0; i < registrations.size(); i++) {
                cout << "\nRegistration #" << (i + 1) << endl;
                registrations[i]->displayInfo();
            }
        }
    }

    // Display system summary
    void displaySystemSummary() {
        cout << "\n=== SYSTEM SUMMARY ===" << endl;
        cout << "Total Students: " << students.size() << endl;
        cout << "Total Courses: " << courses.size() << endl;
        cout << "Total Instructors: " << instructors.size() << endl;
        cout << "Total Registrations: " << registrations.size() << endl;
    }
};

// Main Test Class
int main() {
    cout << "╔════════════════════════════════════════════════════╗" << endl;
    cout << "║ COLLEGE DEPARTMENT REGISTRATION SYSTEM ║" << endl;
    cout << "║ Demonstrating Association & Dependency ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝\n" << endl;

    // Create the registration system
    RegistrationSystem system;

    cout << "--- ADDING INSTRUCTORS ---" << endl;
    // Create instructors
    Instructor* prof1 = new Instructor("I001", "John", "Smith", "j.smith@university.edu", "Computer Science");
    Instructor* prof2 = new Instructor("I002", "Sarah", "Johnson", "s.johnson@university.edu", "Computer Science");
    Instructor* prof3 = new Instructor("I003", "Michael", "Brown", "m.brown@university.edu", "Mathematics");

    system.addInstructor(prof1);
    system.addInstructor(prof2);
    system.addInstructor(prof3);

    cout << "\n--- ADDING COURSES ---" << endl;
    // Create courses
    Course* course1 = new Course("CS101", "Introduction to Programming", 3, 30);
    Course* course2 = new Course("CS201", "Data Structures", 4, 25);
    Course* course3 = new Course("CS301", "Database Systems", 3, 20);
    Course* course4 = new Course("MATH201", "Calculus II", 4, 35);

    system.addCourse(course1);
    system.addCourse(course2);
    system.addCourse(course3);
    system.addCourse(course4);

    // Assign instructors to courses (Association)
    cout << "\n--- ASSIGNING INSTRUCTORS TO COURSES ---" << endl;
    prof1->assignCourse(course1);
    prof1->assignCourse(course2);
    prof2->assignCourse(course3);
    prof3->assignCourse(course4);
    cout << "✓ Instructors assigned to courses" << endl;

    cout << "\n--- ADDING STUDENTS ---" << endl;
    // Create students
    Student* student1 = new Student("S001", "Alice", "Williams", "alice.w@student.edu", "Computer Science");
    Student* student2 = new Student("S002", "Bob", "Davis", "bob.d@student.edu", "Computer Science");
    Student* student3 = new Student("S003", "Charlie", "Miller", "charlie.m@student.edu", "Information Systems");
    Student* student4 = new Student("S004", "Diana", "Garcia", "diana.g@student.edu", "Computer Science");

    system.addStudent(student1);
    system.addStudent(student2);
    system.addStudent(student3);
    system.addStudent(student4);

    cout << "\n--- REGISTERING STUDENTS FOR COURSES ---" << endl;
    // Register students for courses (Demonstrates Dependency)
    system.registerStudentForCourse(student1, course1);
    system.registerStudentForCourse(student1, course2);
    system.registerStudentForCourse(student1, course4);

    system.registerStudentForCourse(student2, course1);
    system.registerStudentForCourse(student2, course3);

    system.registerStudentForCourse(student3, course1);
    system.registerStudentForCourse(student3, course2);

    system.registerStudentForCourse(student4, course2);
    system.registerStudentForCourse(student4, course3);
    system.registerStudentForCourse(student4, course4);

    // Display course information
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║ COURSE INFORMATION ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;

    cout << "\n--- Course 1 ---" << endl;
    course1->displayInfo();

    cout << "\n--- Course 2 ---" << endl;
    course2->displayInfo();

    // Display student information
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║ STUDENT INFORMATION ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;

    cout << "\n--- Student 1 ---" << endl;
    student1->displayInfo();
    cout << "Courses:" << endl;
    for (Course* c : student1->getEnrolledCourses()) {
        cout << " • " << c->getCourseCode() << " - " << c->getCourseName() << endl;
    }

    cout << "\n--- Student 4 ---" << endl;
    student4->displayInfo();
    cout << "Courses:" << endl;
    for (Course* c : student4->getEnrolledCourses()) {
        cout << " • " << c->getCourseCode() << " - " << c->getCourseName() << endl;
    }

    // Test dropping a course
    cout << "\n--- DROPPING A COURSE ---" << endl;
    system.dropCourse(student1, course4);

    // Display all registrations
    system.displayAllRegistrations();

    // Display system summary
    system.displaySystemSummary();

    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║ ASSOCIATION & DEPENDENCY DEMONSTRATED ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    cout << "\nASSOCIATION Examples:" << endl;
    cout << "• Student HAS-A list of Courses (enrolledCourses)" << endl;
    cout << "• Course HAS-A list of Students (enrolledStudents)" << endl;
    cout << "• Course HAS-A Instructor" << endl;
    cout << "• Instructor HAS-A list of Courses (teachingCourses)" << endl;
    cout << "\nDEPENDENCY Examples:" << endl;
    cout << "• Registration class DEPENDS ON Student, Course, Date" << endl;
    cout << "• RegistrationSystem methods DEPEND ON Student & Course" << endl;
    cout << "• Registration uses Date class (temporal dependency)" << endl;

    return 0;
}

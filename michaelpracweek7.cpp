#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    
    string name;
    int age;
    int serviceYear;
    double salary;

public:

    Employee(string n, int a, int sy, double s) {
        name = n;
        age = a;
        serviceYear = sy;
        salary = s;
        cout << "Employee object created: " << name << endl;
    }


    ~Employee() {
        cout << "Employee object destroyed: " << name << endl;
    }


    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    int getServiceYear() {
        return serviceYear;
    }

    double getSalary() {
        return salary;
    }
};
int main() {
    cout << "========== Employee Management System ==========\n" << endl;
    
    Employee emp1("John Smith", 35, 10, 75000.50);
    Employee emp2("Sarah Johnson", 28, 5, 62000.00);
    Employee emp3("Michael Brown", 42, 18, 95000.75);
    
    cout << "\n========== Employee Information ==========\n" << endl;
    
    cout << "Employee 1:" << endl;
    cout << "Name: " << emp1.getName() << endl;
    cout << "Age: " << emp1.getAge() << endl;
    cout << "Service Years: " << emp1.getServiceYear() << endl;
    cout << "Salary: $" << emp1.getSalary() << endl;
    cout << endl;
    
    
    cout << "Employee 2:" << endl;
    cout << "Name: " << emp2.getName() << endl;
    cout << "Age: " << emp2.getAge() << endl;
    cout << "Service Years: " << emp2.getServiceYear() << endl;
    cout << "Salary: $" << emp2.getSalary() << endl;
    cout << endl;
    
    
    cout << "Employee 3:" << endl;
    cout << "Name: " << emp3.getName() << endl;
    cout << "Age: " << emp3.getAge() << endl;
    cout << "Service Years: " << emp3.getServiceYear() << endl;
    cout << "Salary: $" << emp3.getSalary() << endl;
    cout << endl;
    
    cout << "========== Program Ending ==========\n" << endl;
    
    
    return 0;
}
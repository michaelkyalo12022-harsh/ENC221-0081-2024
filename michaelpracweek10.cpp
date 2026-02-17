#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Employee Interface (abstract class in C++)
class Employee {
public:
    virtual string getFirstName() = 0;
    virtual string getInitial() = 0;
    virtual string getLastName() = 0;
    virtual double calculateEarnings() = 0;
    virtual void displayInfo() = 0;
    virtual ~Employee() {}
};

class SalaryEmployee : public Employee {
private:
    string firstName;
    string initial;
    string lastName;
    double monthlySalary;

public:
    SalaryEmployee(string firstName, string initial, string lastName, double monthlySalary) {
        this->firstName = firstName;
        this->initial = initial;
        this->lastName = lastName;
        this->monthlySalary = monthlySalary;
    }

    string getFirstName() override {
        return firstName;
    }

    string getInitial() override {
        return initial;
    }

    string getLastName() override {
        return lastName;
    }

    double calculateEarnings() override {
        return monthlySalary;
    }

    void displayInfo() override {
        cout << "Employee Type: Salary Employee" << endl;
        cout << "Name: " << firstName << " " << initial << ". " << lastName << endl;
        cout << "Monthly Salary: $" << fixed << setprecision(2) << monthlySalary << endl;
        cout << "Monthly Earnings: $" << fixed << setprecision(2) << calculateEarnings() << endl;
    }

    double getMonthlySalary() {
        return monthlySalary;
    }

    void setMonthlySalary(double monthlySalary) {
        this->monthlySalary = monthlySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    string firstName;
    string initial;
    string lastName;
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(string firstName, string initial, string lastName,
                   double hourlyRate, double hoursWorked) {
        this->firstName = firstName;
        this->initial = initial;
        this->lastName = lastName;
        this->hourlyRate = hourlyRate;
        this->hoursWorked = hoursWorked;
    }

    string getFirstName() override {
        return firstName;
    }

    string getInitial() override {
        return initial;
    }

    string getLastName() override {
        return lastName;
    }

    double calculateEarnings() override {
        return hoursWorked * hourlyRate;
    }

    void displayInfo() override {
        cout << "Employee Type: Hourly Employee" << endl;
        cout << "Name: " << firstName << " " << initial << ". " << lastName << endl;
        cout << "Hourly Rate: $" << fixed << setprecision(2) << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Monthly Earnings: $" << fixed << setprecision(2) << calculateEarnings() << endl;
    }

    double getHourlyRate() {
        return hourlyRate;
    }

    void setHourlyRate(double hourlyRate) {
        this->hourlyRate = hourlyRate;
    }

    double getHoursWorked() {
        return hoursWorked;
    }

    void setHoursWorked(double hoursWorked) {
        this->hoursWorked = hoursWorked;
    }
};

int main() {
    cout << "=== Employee Polymorphism Test ===\n" << endl;

    SalaryEmployee* salaryEmp1 = new SalaryEmployee("John", "D", "Smith", 5000.00);
    SalaryEmployee* salaryEmp2 = new SalaryEmployee("Sarah", "M", "Johnson", 6500.00);

    HourlyEmployee* hourlyEmp1 = new HourlyEmployee("Michael", "R", "Brown", 25.50, 160);
    HourlyEmployee* hourlyEmp2 = new HourlyEmployee("Emily", "A", "Davis", 30.00, 140);

    Employee* employees[4];
    employees[0] = salaryEmp1;
    employees[1] = hourlyEmp1;
    employees[2] = salaryEmp2;
    employees[3] = hourlyEmp2;

    cout << "--- Processing All Employees Polymorphically ---\n" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Employee #" << (i + 1) << ":" << endl;
        employees[i]->displayInfo();
        cout << endl;
    }

    double totalPayroll = 0;
    for (int i = 0; i < 4; i++) {
        totalPayroll += employees[i]->calculateEarnings();
    }

    cout << "=== Payroll Summary ===" << endl;
    cout << "Total number of employees: " << 4 << endl;
    cout << "Total monthly payroll: $" << fixed << setprecision(2) << totalPayroll << endl;
    cout << "Average monthly earnings: $" << fixed << setprecision(2) << (totalPayroll / 4) << endl;

    cout << "\n=== Demonstrating Polymorphism ===" << endl;
    cout << "Each employee type calculates earnings differently:" << endl;
    cout << "- SalaryEmployee: Fixed monthly salary" << endl;
    cout << "- HourlyEmployee: Hours worked × Hourly rate" << endl;
    cout << "\nBut we can treat them all as 'Employee' objects!" << endl;

    cout << "\n=== Additional Polymorphism Example ===" << endl;
    cout << "Calling calculateEarnings() on each employee:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << employees[i]->getFirstName() << " "
             << employees[i]->getLastName() << ": $"
             << fixed << setprecision(2) << employees[i]->calculateEarnings() << endl;
    }

    // Clean up
    delete salaryEmp1;
    delete salaryEmp2;
    delete hourlyEmp1;
    delete hourlyEmp2;

    return 0;
}

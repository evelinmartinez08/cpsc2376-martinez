#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2) << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << std::fixed << std::setprecision(2) << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << std::setprecision(0) << commissionRate * 100 << "%, Salary: $"
            << std::fixed << std::setprecision(2) << calculateSalary() << std::endl;
    }
};

std::vector<Employee*> readEmployeesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::vector<Employee*> employees;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        int id;
        std::string name;
        iss >> type >> id >> name;

        if (type == "Salaried") {
            double monthlySalary;
            iss >> monthlySalary;
            employees.push_back(new SalariedEmployee(name, id, monthlySalary));
        }
        else if (type == "Hourly") {
            double hourlyRate;
            int hoursWorked;
            iss >> hourlyRate >> hoursWorked;
            employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
        }
        else if (type == "Commission") {
            double baseSalary, salesAmount, commissionRate;
            iss >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(new CommissionEmployee(name, id, baseSalary, salesAmount, commissionRate));
        }
        else {
            throw std::runtime_error("Invalid employee type in file: " + type);
        }
    }

    file.close();
    return employees;
}

int main() {
    try {
        std::vector<Employee*> employees = readEmployeesFromFile("employees.txt");

        for (const auto& employee : employees) {
            employee->displayInfo();
        }

        for (const auto& employee : employees) {
            delete employee;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
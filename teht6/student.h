#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    Student(std::string n, int a) : Name(n), Age(a) {}

    void setAge(int a) {
        Age = a;
    }

    void setName(std::string n) {
        Name = n;
    }

    std::string getName() const {
        return Name;
    }

    int getAge() const {
        return Age;
    }

    void printStudentInfo() const {
        std::cout << "Name: " << Name << ", Age: " << Age << std::endl;
    }

private:
    std::string Name;
    int Age;
};

#endif // STUDENT_H

#include "header.h"
#include <iostream>
using namespace std;

void student::CreateStudent(int id, string name, float gpa) {
    s.id = id;
    s.name = name;
    s.gpa = gpa;
}

void student::displayInfo() {
    cout << "Student ID: " << s.id << endl;
    cout << "Student Name: " << s.name << endl;
    cout << "Student GPA: " << s.gpa << endl;
}

void all_student::addStudent(int id, string name, float gpa) {
    if (count < 100) {
        s_array[count].CreateStudent(id, name, gpa);
        count++;
    } else {
        cout << "Student array is full!\n";
    }
}

void all_student::displayAllStudents() {
    for (int i = 0; i < count; i++) {
        s_array[i].displayInfo();
        cout << "------------------\n";
    }
}

void quest_3() {
    all_student class1;
    class1.addStudent(12345,"John Doe",3.5);
    class1.addStudent(67890,"Jane Smith",3.8);
    class1.displayAllStudents();
}

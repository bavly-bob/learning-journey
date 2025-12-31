#include "header.h"
#include <iostream>
using namespace std;

section::section()
    : course_name(""), section_number(0),
      capacity(30), enrolled_students(0) {}

section::section(int max_capacity)
    : course_name(""), section_number(0),
      capacity(max_capacity), enrolled_students(0) {}

bool section::alreadyRegistered(int id) {
    for (int i = 0; i < enrolled_students; i++)
        if (this->id[i] == id) return true;
    return false;
}

void section::Register(string id) {
    int student_id = stoi(id);
    if (enrolled_students < capacity && !alreadyRegistered(student_id)) {
        this->id[enrolled_students] = student_id;
        enrolled_students++;
        cout << "Student with ID " << id << " registered successfully.\n";
    } else {
        cout << "Cannot register student.\n";
    }
}

void section::display_id_list() {
    cout << "Enrolled Students IDs:\n";
    for (int i = 0; i < enrolled_students; i++)
        cout << this->id[i] << endl;
}

void quest_2() {
    section sec;
    sec.Register("12345");
    sec.Register("67890");
    sec.display_id_list();
}

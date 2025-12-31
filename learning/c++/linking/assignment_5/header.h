#pragma once
#include <string>
using namespace std;

class book {
public:
    book();
    book(string t, string a, int p, float pp);

    float getTotalCost();
    void displayInfo();
    void change_price_per_page(float new_price);
    float get_price_per_page();

private:
    string title;
    string author;
    int pages;
    float price_per_page;
};

class section {
public:
    section();
    section(int max_capacity);

    bool alreadyRegistered(int id);
    void Register(string id);
    void display_id_list();

private:
    std::string course_name;
    int section_number;
    int capacity;
    int id[50];
    int enrolled_students;
};

struct single_student_info {
    string name;
    int id;
    float gpa;
};

class student {
public:
    void CreateStudent(int id,string name, float gpa);
    void displayInfo();

private:
    single_student_info s;
};

class all_student {
public:
    void addStudent(int id,string name, float gpa);
    void displayAllStudents();

private:
    student s_array[100];
    int count = 0;
};

// Function declarations
void quest_1();
void quest_2();
void quest_3();

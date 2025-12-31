#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    float grade;
};

int main ()
{
    student s1;
    cout <<" enter student name: ";
    cin >> s1.name;
    cout <<" enter student age: ";
    cin >> s1.age;
    cout <<" enter student grade: ";
    cin >> s1.grade;
    cout << "Student Details:\n";
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Grade: " << s1.grade << endl;
    return 0;
}

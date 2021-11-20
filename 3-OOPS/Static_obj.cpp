#include <iostream>
using namespace std;

class Student
{
public:
    int age, rollNumber;
    static int noOfStudents; // total no of students present

    Student()
    {
        noOfStudents++;
    }
};

int Student :: noOfStudents = 20; //initialize static data member value.s

int main()
{
    Student s1, s2, s3, s4, s5, s6;
    cout << Student :: noOfStudents << endl;
    return 0;
}
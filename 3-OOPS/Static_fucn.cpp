#include <iostream>
using namespace std;

class Student
{
    static int noOfStudents; // total no of students present

public:
    int age, rollNumber;

    Student()
    {
        noOfStudents++;
    }

    int getRollNumber(){
        return rollNumber;
    }

    static int getNoOfStudent(){
        return noOfStudents;
    }
};

int Student :: noOfStudents = 0; //initialize static data member value.s

int main()
{
    Student s1, s2, s3, s4, s5, s6;
    cout << Student :: getNoOfStudent() << endl;
    return 0;
}
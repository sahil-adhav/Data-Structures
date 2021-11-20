#include<iostream>
using namespace std;

class Student{
    public:
        int age;
        int const rollNumber;
        //Initializing List
        Student(int r, int age) : rollNumber(r), age(age){
            cout << r << " " << age << endl;
            }
};

int main()
{
    Student s1(5, 10);  
    return 0;
}
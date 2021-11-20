#include <iostream>
using namespace std;

class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        //shallow copy
        this->name = name;
    }

    void display()
    {
        cout << age << " " << name << endl;
    }
};

int main()
{
    char name[] = "abcde";
    Student s1(20, name);
    s1.display();
    name[3] = 'X'; // inserting x at 3 index of name
    Student s2(10, name);
    s2.display();
    s1.display();
    return 0;
}

/*
Output : 
20 abcde       
10 abcXe       
20 abcX

Value of s1 should be same, but it is changing.
because we copied it shallow and not deep
we passed it by refrence so changes are reflected everywhere.
*/
#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        //Deep Copy
        this->name = new char[strlen(name) + 1];  //+1 for '/0'.
        strcpy(this->name, name);
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
20 abcde

Now here value of s1 is not changing via deep copy contsrcutor.
*/
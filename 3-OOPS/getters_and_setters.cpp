#include<iostream>
using namespace std;

class Student{
    public:
        int roll_No;
    private:
        int age;
    public:
        void display(){
            cout << age << " " << roll_No << endl; 
        }
        int getAge(){          //getter method, as we are unable to access age 
            return age;        //as it is private so we are getting age through
        }                      //functions.
        void setAge(int a){
            age = a;
        }
};

int main()
{
    Student *s1 = new Student;   //dynamically declaring objects.
    s1->roll_No = 20;
    s1->setAge(22);
    s1->display();
    return 0;
}
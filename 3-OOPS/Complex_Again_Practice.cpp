#include<iostream>
using namespace std;

class ComplexNumbers {
    int real;
    int imaginary;
    public:
        ComplexNumbers(int real, int imaginary){
            this -> real = real;
            this -> imaginary = imaginary;
        }
        void print(){
            cout << this -> real << " + " << "i" << this -> imaginary << endl;
        }
        void plus(ComplexNumbers  c){
            int real = real + c.real;
            int imaginary = imaginary + c.imaginary;
            this -> real = real;
            this -> imaginary = imaginary;
        }
        void multiply(ComplexNumbers c){
            int real = (this -> real * c.real) - (this -> imaginary * c.imaginary);
            int imaginary = (this -> real * c.imaginary) + (this -> imaginary * c.real);

            this -> real = real;
            this -> imaginary = imaginary;
        }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
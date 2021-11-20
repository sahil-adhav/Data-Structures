#include<iostream>
using namespace std;

class Fraction{
    private:
        int numerator, denominator;

    public:
        Fraction(int numerator, int denominator){
            this -> numerator = numerator;
            this -> denominator = denominator;
        }

        void display(){
            cout << this -> numerator << " / " << this -> denominator << endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min( this-> numerator, this -> denominator);
            for (int i = 1; i <= j; i++)
            {
                if(this -> numerator % i == 0 && this -> denominator % i == 0){
                    gcd = i;
                }
            }
            this -> numerator =  this -> numerator/gcd;           
            this -> denominator =  this -> denominator/gcd;           
        }

        void add(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;
            int num = (x * numerator) + (y * f2.numerator);

            numerator = num;
            denominator = lcm;

            simplify();
        }
};

int main()
{
    Fraction a1(10, 2);   
    Fraction a2(15, 4);

    a1.add(a2);
    a1.display();   
    a2.display();   
    return 0;
}
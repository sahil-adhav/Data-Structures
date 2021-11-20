#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }

    void simlify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
            this->numerator = this->numerator / gcd;
            this->denominator = this->denominator / gcd;
    }

    //F1 = 10/2, F2 = 15/4
    //lcm = 8
    // F1 + F2 => 10 x 4/8 + 15 x 2/8
    //here we will consider 4 and 2 as x and y.

    void add(Fraction f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        numerator = num;
        denominator = lcm;

        simlify();
    }
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.add(f2);

    f1.print();
    f2.print();

    return 0;
}
#include <iostream>
using namespace std;

class Fraction
{
    int numerator, denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void display()
    {
        cout << this->numerator << " / " << this->denominator << endl;
    }

    void simplify()
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

    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / (f2.denominator);
        int num = (x * numerator) + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    Fraction operator-(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / (f2.denominator);
        int num = (x * numerator) - (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    //pre-increment ++
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    //post-increment ++
    Fraction operator++(int)
    { // int specifies that it is a post increment Operator.
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    // += operator

    Fraction &operator+=(Fraction const &f2)
    {                                                   // with void it will worl fine but
        int lcm = denominator * f2.denominator;         //we wont be able to nest it like
        int x = lcm / denominator;                      // int i = 5, j = 2;
        int y = lcm / (f2.denominator);                 // i+=j  {we can do this in void} but
        int num = (x * numerator) + (y * f2.numerator); // not (i+=j)+=j, we can this in
        numerator = num;                                // Fraction return data type.
        denominator = lcm;
        simplify();
        return *this;
    }
};

int main()
{
    Fraction f1(10, 3);
    Fraction f2(5, 2);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    f1.display();
    f2.display();
    f3.display();
    f4.display();
    f5.display();
    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    //Pre-Increment Opreator ++i
    Fraction f6(10, 2);
    f6.display();
    ++f6;
    f6.display();
    ++(++f6);
    f6.display();
    //Post-Increment Operator i++;
    Fraction f7 = f1++;
    f1.display();
    f7.display();
    // += Operator
    f1 += f2;
    f1.display();
    f2.display();
    (f1 += f2) += f2; // nesting
    f1.display();
    f2.display();
    return 0;
}
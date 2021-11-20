#include <iostream>
using namespace std;

int Power(int, int);

int main()
{
    int x, n, result;

    cin >> x;

    cin >> n;

    result = Power(x, n);
    cout << result;

    return 0;
}

int Power(int x, int n)
{
    if (n != 0)
        return (x * Power(x, n-1));
    else
        return 1;
}
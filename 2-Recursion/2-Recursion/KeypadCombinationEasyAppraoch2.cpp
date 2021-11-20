#include<iostream>
using namespace std;

string getString(int d)
{
    if (d == 2)
    {
        return "abc";
    }
    if (d == 3)
    {
        return "def";
    }
    if (d == 4)
    {
        return "ghi";
    }
    if (d == 5)
    {
        return "jkl";
    }
    if (d == 6)
    {
        return "mno";
    }
    if (d == 7)
    {
        return "pqrs";
    }
    if (d == 8)
    {
        return "tuv";
    }
    if (d == 9)
    {
        return "wxys";
    }
    return " ";
}

void print_keypad(int num, string outputSoFar){
    if(num == 0){
        cout << outputSoFar << endl;
        return;
    }
    int lastDigit = num%10;
    int smallNumber = num/10;
    string options = getString(lastDigit);
    for (size_t i = 0; i < options.length(); i++)
    {
        print_keypad(smallNumber,outputSoFar+options[i]);
    }
    
}

void printKeypad(int num){
    print_keypad(num, "");
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}
#include<iostream>
using namespace std;

void printString(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    printString(input.substr(1), output);
    printString(input.substr(1), output+input[0]);
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    printString(input, output);
    return 0;
}
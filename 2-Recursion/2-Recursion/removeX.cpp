#include<iostream>
using namespace std;

void removeX(char str[]){
    if(str[0] == '\0'){
        return;
    }
    if(str[0] != 'x'){
        removeX(str+1);
    }else{
        int i = 1; // initialsed i here so that we have access outside for loop.
        for (; str[i] != '\0'; i++)
        {
            str[i-1] = str[i]; //shifting elements.
        }
        str[i-1] = str[i];
        removeX(str);
    }
}

int length(char str[]){
    //length of string using recusrion.
    if(str[0] == '\0'){
        return 0; //base case
    }
    int smallStringLength = length(str+1);
    return 1+smallStringLength;
}

int main()
{
    char str[100];
    cin >> str;
    int l = length(str);
    cout << l << endl;
    removeX(str);
    cout << str << endl;
    l = length(str);
    cout << l << endl;
}
#include<iostream>
using namespace std;

int countZeros(int n) 
{
   if(n <= 9){
       if(n == 0){
           return 1;
       }else{
           return 0;
       }
   }
       int lastDigit = n%10;
       int count = 0;

        if(lastDigit == 0){
            count = 1;
        }
       return count + countZeros(n/10);
}

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
    return 0;
}
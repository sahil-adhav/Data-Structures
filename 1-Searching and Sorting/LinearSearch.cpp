#include<iostream>
using namespace std;

int linearSearch(int arr[], int x, int n){
    int i;
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;        
}

int main()
{
    int i, n;
    cin >> n;
    int arr[10];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int result = linearSearch(arr, x, n);
    if (result == -1)
    {
        cout << "Element not found" << endl;
    }else{
        cout << "Element matched!" << endl;
    }
    
    return 0;
}
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        //finding minimum in an array.
        int min = arr[i], minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        //swapping variables
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;      
    }
    
}

int main()
{
    int arr[10];
    int n;
    cout << "Enter value of n : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array unsorted : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    cout << "Array Sorted" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<  endl;    
    return 0;
}
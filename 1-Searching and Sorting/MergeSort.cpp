#include <iostream>
using namespace std;

void merge(int input1[], int size1, int input2[], int size2, int ans[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (input1[i] < input2[j])
        {
            ans[k] = input1[i];
            i++;
            k++;
        }
        else
        {
            ans[k] = input2[j];
            j++;
            k++;
        }
    }
    while (i < size1)
    {
        ans[k] = input1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        ans[k] = input2[j];
        j++;
        k++;
    }
}

void mergeSort(int input[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int input1[100], input2[100];
    int mid = size / 2;
    int size1 = mid, size2 = size - mid;
    for (int i = 0; i < mid; i++)
    {
        input1[i] = input[i];
    }
    int k = 0;
    for (int i = mid; i < size; i++)
    {
        input2[k] = input[i];
        k++;
    }
    mergeSort(input1, size1);
    mergeSort(input2, size2);
    merge(input1, size1, input2, size2, input);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}
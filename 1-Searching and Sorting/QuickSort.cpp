#include<iostream>
using namespace std;

int partition(int input[], int start, int end){
    int pivot = input[start];
    int countSmaller = 0;
    for (int i = start+1; i <= end; i++)
    {
        if(input[i] <= pivot){
            countSmaller++;
        }
    }
    int pivotIndex = countSmaller+start;
    int temp = input[start];
    input[start] = input[pivotIndex];
    input[pivotIndex] = pivot;

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        if(input[i] <= pivot){
            i++;
        }else if(input[j] >= pivot){
            j--;
        }else{
            int temp = input[j];
            input[j] = input[i];
            input[i] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int input[], int start, int end){
    if(start>=end){
        return;
    }
    int c = partition(input, start, end);
    quickSort(input, start, c-1);
    quickSort(input, c+1, end);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



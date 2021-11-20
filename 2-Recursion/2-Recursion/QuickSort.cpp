#include<iostream>
using namespace std;

int partition(int a[], int start, int end){
    int pivot = a[start];
    int countSmaller = 0;
    for (int i = start+1; i <= end; i++)
    {
        if(a[i] < pivot){
            countSmaller++;
        }
    }
    int pivotIndex = countSmaller+start;
    int temp = a[start];
    a[start] = a[pivotIndex];
    a[pivotIndex] = pivot;
    
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){
        if(a[i] < pivot){
            i++;
        }else if(a[j] > pivot){
            j--;
        }else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quick_Sort(int a[], int start, int end){
    if(start>=end){
        return;
    }
    int c = partition(a, start, end);
    quick_Sort(a, start, c-1);
    quick_Sort(a, c+1, end);
}

void quickSort(int input[], int size) {
    quick_Sort(input, 0, size-1);
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



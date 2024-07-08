#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>  
using namespace std;
  
// Function to swap numbers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
/* This function takes last element as pivot,
   places the pivot element at its correct
   position in sorted  array, and places
   all smaller (smaller than pivot) to left
   of pivot and all greater elements to 
   right of pivot */
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  
/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}
  
// Driver code
int main()
{
  
   // int n = 5;
   // int arr[n] = { 4, 2, 6, 9, 2 };
   int size;
    cout << "Enter the array size number::";
    cin >> size;
    int Rand[size];
    for(int r= 0; r <size; r++)
    Rand[r] = rand()%10;
    int arr[size];
    for(int r = 0; r<size ; r++){
        arr[r] = Rand[r];
    }
    chrono::steady_clock sc;
    auto start = sc.now();
  
    quickSort(arr, 0, size - 1);
   auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
    cout<<"Operation took: "<<time_span.count()<<" seconds "<<endl;
    cout<<"Sorted array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
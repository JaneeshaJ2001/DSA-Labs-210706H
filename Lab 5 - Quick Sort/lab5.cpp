#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}




//calculate median
double findMedian(int a[], int n){
    double median;
    if(n%2 == 0)
        median=(a[n/2]+a[(n/2)-1])/2.0;
        
    else
        median=a[n/2];
    return median;
     
}

int main()
{
    int size;
    cout << "Enter size of the array : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i<size ; i++){
        cin >> arr[i];
    }

    for (int k = 0;k < size ; k++) {
        
        insertionSort(arr, k+1);
        cout << "Sorted array in ascending order = ";
        printArray(arr, k+1);
        //cout << "Median is : " << findMedian(arr, k+1) << endl;
        cout << "Median = ";
        printf("%.1f",findMedian(arr, k+1));
        cout << "\n\n";
    }

    return 0;
}
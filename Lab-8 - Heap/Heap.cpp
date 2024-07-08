#include <iostream>
#include<cmath>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   //initialize an integer variable max to store the index of maximum element among root or left or right 
   int max;

   //since the root is considered as the index 0, to access the left child use 2*i formula and to access right child use 2*i+1 formula
   int left = 2*root + 1;
   int right = 2*root + 2;

   //consider the case when left child is larger than the parent value then assign left as max
   //at the same time check whether the left index is lesser than the size of array
  if (left < n && arr[left] > arr[root]){
   max = left;
  }
  //consider the case when arr[root] is larger than the arr[left] then assign root as max
  else{
   max = root;
  }

   //consider the case when arr[right] is larger than the arr[max] then assign right as max 
   //at the same time check whether the right index is lesser than the size of array  
   if (right < n && arr[right] > arr[max]){
      max = right;
   }

   //if max equals root ,no need to perform heapify operation,, since is is already set the root as the the index of largest element
   if (max != root){
      swap(arr[root], arr[max]);
      heapify(arr, n, max);
   }
}



//here we build a max heap applying bottom to top approach by calling heapify operation to each sub tree using for loop starting  from non leaf nodes
//floor(n/2) gives the index of non leaf nodes

void buildMaxHeap(int arr[], int n){
    
   for (int i = floor((n-1)/2) ; i>=0 ; i--){
      heapify(arr, n, i);
   }
}  



// implementing heap sort
void heapSort(int arr[], int n)
{
   // build max heap
   buildMaxHeap(arr, n);

   // extracting elements from heap one by one
   //by swapping the ist element and the last right most element we get the maximum elemnt at the end of the array
   //by doing this for all the elements of the tree finally we get a sorted array

   for (int i=n-1 ; i>=0; i--){
    swap(arr[0], arr[i]);
    //reduce the size by 1 as we already kept the largest elemnnt at the end of the array
    n--;
    //call  again heapify function in order to build the max heap as max heap concept was broken due to swapping
    heapify(arr, n, 0);
   }
   
   
}
  


/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  


  
// main program
int main()
{  
   /*
   int heap_arr[] = {52,78,46,92,12,63,75,36};
   */
   
   int heap_arr[8];
   cout << "Enter number : " << "\n";


   for (int i= 0; i<8; i++){
        cin >> heap_arr[i];
    }


   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
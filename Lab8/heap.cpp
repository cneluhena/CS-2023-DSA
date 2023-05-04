//created by cneluhena

#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;  //index of non leaf node
   int left_child = 2*root + 1;  //index of right child
   int right_child = 2*root + 2;  //index of left child

   //change largest if left child is greater than largest indexed element
   if (left_child < n && (arr[left_child] > arr[root])){
         largest = left_child;  
   }

   //change largest if right child is greater than largest indexed element
   if (right_child < n && (arr[right_child] > arr[largest])){
         largest = right_child;
   }

   //run if largest not equals i
   if (largest != root){
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int start = floor((n/2)-1);
   for (int i = start; i >=0 ; i--){
      heapify(arr, n, i);
   }
   
   // extracting elements from heap one by one
   for (int i=n-1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
   //getting number of inputs from the user
   vector<int> input_array;
   cout << "Enter array: ";
   int a;
   while (true){
      cin >> a;
      if (a==-1){
         break;  //terminate inputing when enter -1
      }
      else if (a < 0){
         continue;
      }
      else{
         input_array.push_back(a);
      }
   }

   int n = input_array.size();
   int heap_arr[n];
   for (int i=0; i < n; i++){
      heap_arr[i] = input_array[i];
   }
  
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

#include <iostream>
using namespace std;
  

int partition(int arr[], int start, int end){

    int pivot = arr[end];
    int i = start-1;
    for (int j=start; j<= end -1; j++){
        if (arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
            
    return i;
}
  
void quickSortIterative(int arr[], int l, int h)
{
    
    int stack[h - l + 1];
    int top = -1;
  
    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
  
        int p = partition(arr, l, h);
  
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
      
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

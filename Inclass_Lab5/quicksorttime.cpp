#include <iostream>
#include <ctime>
#include <math.h>
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


void quicksort(int arr[], int start, int end){
    if (end <= start)
        return;
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot-1);
    quicksort(arr, pivot+1, end);
    
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



int main(){
    int intArr[] = {2000, 5000, 10000, 15000, 20000, 25000};
    for (int x=0; x <6; x++){
        
        int n;
        n = intArr[x];
        cout<<"Total Elements in Array: "<< n<<endl;
        int arr[n];
        int arr1[n];
        int g = 0;
        for(int i=0;i<n;i++){
        int g = rand()%100;
          arr[i]=g;
          arr1[i] = g;
        }
    
        int arr_size = sizeof(arr) / sizeof(arr[0]);
        double sum_1 = 0;
        double sum_2 = 0;
        for (int j=0 ; j < 6; j++){
            clock_t start_1 = clock();
            quicksort(arr, 0, arr_size - 1);
            clock_t end_1 = clock();
            double duration_1 = ((float)(end_1-start_1)/CLOCKS_PER_SEC)*pow(10, 6);
            sum_1 += duration_1;

            clock_t start_2 = clock();
            quickSortIterative(arr, 0, arr_size-1);
            clock_t end_2 = clock();
            double duration_2 = ((float)(end_2-start_2)/CLOCKS_PER_SEC)*pow(10, 6);
            sum_2 += duration_2;


        }
        double average_1 = sum_1 / 6;
        double average_2 = sum_2 / 6;
        cout << "Average Time Taken for Recursive Quick Sort: " << average_1 << " Microseconds"<< endl;
        cout << "Average Time Taken for Iterative Quick Sort: " << average_2 << " Microseconds\n"<< endl;

        
        
    }
}

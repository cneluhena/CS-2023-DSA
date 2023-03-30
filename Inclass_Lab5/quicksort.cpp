#include <iostream>
using namespace std;


//partitioning the array
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


int main(){
    int array[] = {10, 2, 5, 8, 2, 4, 6, 1};
    int arr_length = sizeof(array)/sizeof(array[0]);
    quicksort(array, 0, arr_length-1);
    for (int k=0; k< arr_length; k++){
        cout << array[k] << " ";
    }

}

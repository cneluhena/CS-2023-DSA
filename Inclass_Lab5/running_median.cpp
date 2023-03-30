#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

//implementing insertion sort
void insertion_sort(vector<int>& arr)
{
    for(int j = 1; j < arr.size(); j++)
    {
      int temp = arr[j];
      int i = j-1;

      while(i >= 0 && arr[i] > temp)
      {
         arr[i+1] = arr[i];
         i--;
      }
      arr[i+1] = temp;
    }
}

//finding median
void findMedian(vector<int> arr){
    int arr_length = arr.size();
    float median;

    //if length of array is even
    if (arr_length % 2 == 0){
        float ele_1 = arr[(arr_length / 2) -1];
        float ele_2 = arr[(arr_length) / 2];
        median = (ele_1 + ele_2) / 2;
    } 

    //if length of array is odd
    else {
        int median_index = ceil(arr_length / 2);
        median = arr[median_index];
    }

    cout << fixed << setprecision(1) << median << endl; 

}


int main(){
    vector <int> array = {4 , 10 , 5, 3};
    vector <int> subarr;
    for (int i=0; i < array.size(); i++){
        subarr.push_back(array[i]);
        
        insertion_sort(subarr);
        for (int x= 0; x < subarr.size() ; x++){
            cout << subarr[x] << " ";
        }
        cout << " ";
        findMedian(subarr);
        

    }
}


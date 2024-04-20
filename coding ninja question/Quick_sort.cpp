#include<iostream>
#include<vector>
using namespace std;


int partition( vector<int>& arr, int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for(int i = start+1; i<=end; i++) {
        if(arr[i] <=pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quick_Sort(vector<int>& arr, int start, int end) {

    if(start >= end) 
        return ;

    int part = partition(arr, start, end);

    quick_Sort(arr, start, part-1);

    quick_Sort(arr, part+1, end);

}



int main() {

    vector<int> arr = {4,2,3,7,1,89,6,2,12,4};
    quick_Sort(arr, 0, arr.size()-1);

    for(int i=0; i<arr.size(); i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}
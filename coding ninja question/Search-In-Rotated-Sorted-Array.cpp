#include<iostream>
using namespace std;
int getPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s , int e , int k){
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    while (start <= end)
        {
        if (arr[mid] == k)
        {
        return mid;
        }
    // go to right
        else if (k > arr[mid])
        {
        start = mid + 1;
        }
    // go to left
        else
        {
        end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
     
    int main(){
    int arr[5] = {12,15,18,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    int pivot = getPivot(arr,n);

   if(k >=arr[pivot] && k <=arr[n-1]){
         cout <<  binarySearch(arr,pivot,n-1,k);
     }
     else{
         cout << binarySearch(arr,0,pivot-1,k);
     }
    return 0;
}
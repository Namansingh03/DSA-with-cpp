//? 852 - Peak Index in a Mountain
#include<iostream>
using namespace std;
int mountain_array(int arr[] , int n ){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    
    while (start <= end)
    {
        if(arr[mid] <  arr[mid+1]){
            start = mid +1;
        }
        else{
           end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}
 
    int main(){

    int arr[7] = {0,1,2,5,3,0};

    cout << mountain_array(arr,7);
    
    return 0;
}
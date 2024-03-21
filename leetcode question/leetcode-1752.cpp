//! Check if Sorted and Rotated array
#include<iostream>
using namespace std;
bool check(int nums[], int n) {
        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]){
            count++;
        }
        return count<=1;
    }
 
    int main(){
    int arr[5] = {3,4,5,1,2};
    cout << check(arr,5) << endl;
    return 0;
}
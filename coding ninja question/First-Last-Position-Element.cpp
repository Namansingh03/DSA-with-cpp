#include<iostream>

using namespace std;
// ! for the first occurring element
int first_occurrence(int arr[], int n , int key){
       int start = 0;
       int end = n - 1;
       int mid = start + (end-start)/2;
       int ans = -1;

       while (start<=end)
       {
         if(arr[mid]==key){
                ans = mid;
                end = mid - 1;
         }
         else if (arr[mid]>key)
         {
            end = mid - 1;
         }
         else
         {
            start = mid + 1;
         }
         mid = start + (end-start)/2;
         
       }
       
    return ans;
}

// ! for the last occurring element
int last_occurrence(int arr[], int n , int key){
       int start = 0;
       int end = n - 1;
       int mid = start + (end-start)/2;
       int ans = -1;

       while (start<=end)
       {
         if(arr[mid]==key){
                ans = mid;
                start = mid + 1;
         }
         else if (arr[mid]>key)
         {
            end = mid - 1;
         }
         else
         {
            start = mid + 1;
         }
         mid = start + (end-start)/2;
         
       }
       
    return ans;
}
 
    int main(){
    int arr_1[] = {0,1,2,2,2,2,3,4};
    int n = sizeof(arr_1)/sizeof(arr_1[0]);
    int k = 2;

    cout << "first occurrence of " << k << " is: " << first_occurrence(arr_1,n,k) << endl;
    cout << "last occurrence of " << k << " is: " << last_occurrence(arr_1,n,k) << endl;
    return 0;
}
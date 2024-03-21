//! merge sorted arrays
#include<iostream>
using namespace std;
void merge(int nums1[], int n , int nums2[] , int m){
     int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}
    int main(){
    int nums1[6] = {1,2,3};
    int nums2[3] = {2,3,6};

    merge(nums1,6,nums2,3);

    for (int i = 0; i <= 6; i++)
    {
        cout << nums1[i] << " ";
    }
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, target, mid + 1, right);
        else
            return binarySearch(arr, target, left, mid - 1);
    }

    return -1;
}

int search(vector<int> &nums, int target) {
    //! using recursion
    return binarySearch(nums, target, 0, nums.size() - 1);

    //! using binary search algorithm
    //  int left = 0;
    // int right = arr.size() - 1;

    // while (left <= right) {
    //     int mid = left + (right - left) / 2;

    //     if (arr[mid] == target)
    //         return mid;
    //     else if (arr[mid] < target)
    //         left = mid + 1;
    //     else
    //         right = mid - 1;
    // }

    // return -1;
}
 
    int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 7;

    cout << search(nums, target) << endl;
    return 0;
}
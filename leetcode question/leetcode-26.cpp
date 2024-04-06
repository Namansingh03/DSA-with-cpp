#include <vector>
#include<iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
   
    int uniqueCount = 1; 
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

// Example usage:
int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    
    int newLength = removeDuplicates(nums);
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    
    return 0;
}

//! Rotated array
#include<iostream>
#include<vector>
using namespace std;
void rotatedArray(vector<int> nums , int k){
    vector<int>temp(nums.size());
        for(int i=0; i<nums.size();i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        nums = temp;
}
 
    int main(){
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    int k = 3;

    rotatedArray(nums,k);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
    return 0;
}
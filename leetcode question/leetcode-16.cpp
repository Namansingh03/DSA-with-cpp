#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size(); i++)
    {
        int start = i+1;
        int end = nums.size() - 1;

        while (start < end){
            int currentSum = nums[i] + nums[start] + nums[end];
            if(abs(target - currentSum) < abs(target - closestSum)){
                closestSum = currentSum;
            }
            if(currentSum < target){
                 start++;
            }
            else if (currentSum > target){
                end--;
            }
            else{
                return target;
            }
        }
    }

    return closestSum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << threeSumClosest(nums, target) << endl;
    return 0;
}
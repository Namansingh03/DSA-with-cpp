#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;

        for(int i=0; i<nums.size(); ++i){
            int comp = target - nums[i];
            for(int j=i+1; j<nums.size(); ++j){
               if(nums[j] == comp){
                  ans.push_back(i);
                  ans.push_back(j);
                  return ans;
               }
            }
        }
        return ans;
}

int main()
{
    vector<int> arr = {2 , 7, 11, 15};

    vector<int> result = twoSum(arr,9);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "" ;
    }
    
    return 0;
}
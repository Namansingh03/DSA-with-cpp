#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> findTriplets(vector<int> nums)
{
      vector<vector<int>> triplets;
      int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int start = i + 1;
        int end = n - 1;
        int target = 0 - nums[i];

        while (start < end) {
            int sum = nums[start] + nums[end];

            if (sum == target) {
                vector<int>ans;
                ans.push_back(nums[i]);
                ans.push_back(nums[start]);
                ans.push_back(nums[end]);
                triplets.push_back(ans);

                while (start < end && nums[start] == nums[start + 1]) start++;
                while (start < end && nums[end] == nums[end - 1]) end--;

                start++;
                end--;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
    }

    return triplets;
}


int main()
{
    vector<int> v = {1, 1, 2, 2, 1, 1};
    int n = v.size();
    int k = 4;

    vector<vector<int>> result = findTriplets(v);

    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> &result, int index)
{
    if (index >= nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, result, index + 1);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    solve(nums, result, 0);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans(permute(nums));
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
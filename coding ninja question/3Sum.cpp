#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
      vector<vector<int>> triplets;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int start = i + 1;
        int end = n - 1;
        int target = K - arr[i];

        while (start < end) {
            int sum = arr[start] + arr[end];

            if (sum == target) {
                vector<int>ans;
                ans.push_back(arr[i]);
                ans.push_back(arr[start]);
                ans.push_back(arr[end]);
                triplets.push_back(ans);

                while (start < end && arr[start] == arr[start + 1]) start++;
                while (start < end && arr[end] == arr[end - 1]) end--;

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

    vector<vector<int>> result = findTriplets(v, n, k);

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
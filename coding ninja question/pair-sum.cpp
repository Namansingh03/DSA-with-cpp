#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s){
   sort(arr.begin(),arr.end());
  
   vector<vector<int>>  result;

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == s) {
            result.push_back({arr[left],arr[right]});
            left++;
            right--;
        } else if (sum < s) {
            left++;
        } else {
            right--;
        }
    }

    return result;

}

int main()
{ 
    vector<int>arr;
 
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(-3);
    arr.push_back(2);
    arr.push_back(-1);

    vector<vector<int>> result = pairSum(arr,0);

    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << ", ";
        }
        cout << "]" << endl;
    }


      
    return 0;
}
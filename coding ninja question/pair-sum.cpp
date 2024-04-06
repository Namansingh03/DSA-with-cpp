#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s){
   sort(arr.begin(),arr.end());
  
    vector<vector<int>> pair;

    for(int i=0; i < arr.size();){
        int num = arr[i];
        int comp = s - arr[i];

        for(int j=i+1; j<arr.size(); j++){
            if(arr[j]==comp){
                pair.push_back({min(num,comp),max(num,comp)});
            }
        }
                i++;
    }
    return pair;

}

int main()
{ 
    vector<int>arr = {2,-3,3,3,2};

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
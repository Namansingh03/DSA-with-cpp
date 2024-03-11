#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> stalls, int k, int mid,int n){
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++)
    {
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    int n = stalls.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int mid, answer = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossible(stalls, k, mid,n))
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);

    int k = 2; /*? number of aggressive cows*/
    
    cout << aggressiveCows(arr,k);
    return 0;
}
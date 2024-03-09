//? pair sum
//! You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

#include <iostream>
#include<vector>

using namespace std;

bool sumTwo(vector<int> arr, int size, int k)
{   
    vector<int> ans;
   for(int i=0; i < arr.size();i++)
    {
       for(int j=i+1; j<arr.size(); j++)
       {
          if(arr[i]+arr[j]==k)
          {
             vector<int> temp;
             temp.push_back(min(arr[i],arr[j]));
             temp.push_back(max(arr[i],arr[j]));
             ans.push_back(temp);
          }
       }
    }
    sort(ans.begin(),ans.end());
}

int main()
{ 
    vector<int>arr;
 
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    cout << sumTwo(arr , 6 , 6) << endl;
      
    return 0;
}
//! Problem statement
//! You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

//! An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

//! Note:
//! 1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
//! 2. The elements in the array need not be distinct.
//! 3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> findTriplets(vector <int>arr, int n, int K) {
	vector<int> result;
  for (int i = 0; i < n;) {
    for (int j = i + 1; j < n - 1;) {
      for (int k = j + 1; k < n - 2;) {
        if (arr[i] == arr[j] == arr[k]) {
          result.push_back(arr[i]);
          i++;
        } else {
          cout << -1;
        }
      }
    }
  }
  return result;
}
 
    int main(){
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    int key = 6;
    int n = arr.size();

    return 0;
}
//? 442 - Find All The Duplicate

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> findDuplicates (vector<int>nums){
   vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        int index = (nums[i]) - 1;
        if (nums[index] < 0)
            result.push_back(abs(index + 1));
        else
            nums[index] = -nums[index];
    }
    
    return result;
}
 
    int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
   
    vector<int> duplicates = findDuplicates(arr);

    cout << "Duplicates: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    return 0;
}


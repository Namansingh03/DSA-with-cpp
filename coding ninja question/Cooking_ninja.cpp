#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;
int dishesInTime(const vector<int>& ranks, int time, int M) {
    int totalDishes = 0;
    for (int rank : ranks) {
        totalDishes += min(time / rank, M);
    }
    return totalDishes;
};

int minTimeToCompleteOrder(const vector<int>& ranks, int M) {
    int maxRank = *max_element(ranks.begin(), ranks.end());
    int maxTime = maxRank * M;
    
    int left = 0, right = maxTime;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (dishesInTime(ranks, mid, M) >= M) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};

    cout << minTimeToCompleteOrder(arr, 11) << endl;

    return 0;
}
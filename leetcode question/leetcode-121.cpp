#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int maxProfit(vector<int> & prices)
{
     if (prices.empty())
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main()
{
    
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfit(arr);

    return 0;
}
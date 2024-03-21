//?1207 unique number of occurrences


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool uniqueOccurrences(vector<int> &arr)
{
    int counts[2001] = {0};
    for (int num : arr)
    {
        counts[num + 1000]++;
    }

    sort(counts, counts + 2001);
    for (int i = 1; i < 2001; ++i)
    {
        if (counts[i] && counts[i] == counts[i - 1])
        {
            return false;
        }
    }

    return true;
};

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);

    int answer = uniqueOccurrences(arr);
    cout << answer << endl;
    return 0;
}
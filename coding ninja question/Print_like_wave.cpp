#include <iostream>
#include <vector>
using namespace std;
void wavePrint(vector<vector<int>> arr)
{
    int nRows = arr.size();
    int mCols = arr[0].size();
    vector<int> result;

    for (int i = 0; i < mCols; i++)
    {

        if (i % 2 == 0)
        {
            for (int j = 0; j < nRows; ++j)
            {
                result.push_back(arr[j][i]);
            }
        }
        else
        {
            for (int j = nRows - 1; j >= 0; --j)
            {
                result.push_back(arr[j][i]);
            }
        }
    }

    for (int a : result)
    {
        cout << a << " ";
    }
}

int main()
{
    vector<vector<int>> arr{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    wavePrint(arr);
    return 0;
}
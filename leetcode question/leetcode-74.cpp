#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
     int rows = matrix.size();
    int cols = matrix[0].size();

    int start = 0, end = rows * cols - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / cols][mid % cols];

        if (element == target)
            return true;
        else if (element < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };

    cout << searchMatrix(arr, 7) << endl;

    return 0;
}
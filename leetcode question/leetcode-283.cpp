//! move zeros
#include <iostream>
using namespace std;

void moveZeros(int nums[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main()
{
    int arr[7] = {1, 0, 6, 9, 0, 5, 0};
    moveZeros(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
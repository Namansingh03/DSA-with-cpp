//? 724 Find Pivot Index
#include <iostream>
using namespace std;
int find_pivot(int arr[], int n)
{
    int left_sum = 0;
    int total_sum = 0;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        total_sum -= arr[i];
        if (total_sum == left_sum)
        {
            return i;
        }

        left_sum += arr[i];
    }
    return -1;
}

int main()
{
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << find_pivot(arr, n);

    return 0;
}
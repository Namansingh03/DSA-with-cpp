#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n ; j++)
        {
            if (arr[min_index] > arr[j])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

int main()
{
    int arr[6] = {2, 6, 3, 8, 0, 1};

    selection_sort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
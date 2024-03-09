//? sort 0 1 2 
//! Problem statement Send feedback                                                 You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list     
#include <iostream>

using namespace std;
void sortArray(int arr[], int n)
{

    // Initialisation
    int start = 0;
    int end = n - 1;

    for (int i = 0; i < n && i <= end;)
    {
        // current element is 0
        if (arr[i] == 0)
        {
            swap(arr[start], arr[i]);
            start++;
            i++;
        }
        // current element is 2
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[end]);
            end--;
        }
        // current element is 1
        else
        {
            i++;
        }
    }
}

void printArray(int arr[], int n)
{
    // Iterate and print every element
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {2, 2, 2, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);
    printArray(arr, n);

    return 0;
}
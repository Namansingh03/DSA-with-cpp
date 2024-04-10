#include <iostream>

using namespace std;

int findUnique(int arr[], int size)
{
    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        answer = answer ^ arr[i];
    }
    
    cout << " the element is : " << answer << endl;
    
    return answer;
}

int main()
{
    int arr[7] = {1, 2, 1, 3, 3, 5, 2};

    findUnique(arr, 7);

    return 0;
}
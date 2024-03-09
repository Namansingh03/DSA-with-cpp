//? square root of number .
//! You are given a positive integer ‘n’.                                             Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

#include <iostream>
using namespace std;
long long int squareRoot(int n){
    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;

    while (start <= end)
    {
        long long int square = mid*mid;
        if(square==n){
            return mid;
        }
        else if(square>n){
            end = mid -1;
        }
        else{
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    int n = 6;

    cout << squareRoot(n) << endl;
    return 0;
}
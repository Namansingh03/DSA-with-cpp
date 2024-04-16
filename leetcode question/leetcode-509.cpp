#include <iostream>
using namespace std;
int fib(int n)
{
    //! non recursion method takes 13 ms
     if(n <= 1){
         return n;
     };
     int ans = fib(n-1) + fib(n-2);
     return ans;

    //! for loop method takes 0ms
    //* int a = 0;
    //* int b = 1, c = 0;
    //* for (int i = 2; i <= n; i++)
    //* {
    //*     c = a + b;
    //*     a = b;
    //*     b = c;
    //* }
    //* if (n == 1)
    //*     return b;
    //* return c;
}

int main()
{
    int n;
    cout << "enter the value" << endl;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}
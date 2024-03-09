//? 1281 - Subtract The Product Ans Sum Of Digit Of an Integer
#include<iostream>

using namespace std;

    int main(){
    int num = 12345;
    int digit;     
    int prod = 1;
    int sum= 0;

    while (num!=0)
    {
        digit = num%10;

        prod = prod * digit;
        sum = sum + digit;

        num = num/10;
    }
    int answer = prod - sum;
    cout << answer << endl;

    return 0;
}
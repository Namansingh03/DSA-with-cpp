#include<iostream>
#include<string>
#include <bits/stdc++.h> 
using namespace std;

string toBinary(int N) {
    string binary;
    
    while (N > 0) {
        binary += (N % 2 == 0) ? '0' : '1';
        N /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

bool isPalindrome(string& str) {
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    
    return true;
}

bool checkPalindrome(long long N)
{
	 string binary = toBinary(N);
    return isPalindrome(binary);
}
 
    int main(){
    cout << checkPalindrome(1123) << endl;
    return 0;
}
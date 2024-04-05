#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool checkPalindrome(string s)
{
   int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        char lChar = tolower(s[left]);
        char rChar = tolower(s[right]);

        if (!isalnum(lChar)) {
            left++;
            continue;
        }
        if (!isalnum(rChar)) {
            right--;
            continue;
        }

        if (lChar != rChar) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    string s;
    cout << " enter the value of string " << endl;
    cin >> s;

    cout << checkPalindrome(s) << endl;
    return 0;
}
//! reverse the words
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverseWords(vector<char> &s)
{

    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    i = 0;
    for (int j = 0; j <= s.size(); j++)
    {
        if (j == s.size() || s[j] == ' ')
        {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
}

int main()
{
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
  
    for (auto &p : s)
    {
        cout << p;
    }
    cout << endl;

    reverseWords(s);

    for (auto &p : s)
    {
        cout << p;
    }
    cout << endl;

    return 0;
}
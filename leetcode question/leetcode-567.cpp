#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool checkInclusion(string s1, string s2){
    if(s1.size() < s2.size()) return false;

    vector<char> count(26,0);

    for(char c : s1){
        count[c - 'a']++;
    }

    int left = 0 , right = 0;

    while (right < s2.size())
    {
        count[s2[right]]--;
        right++;
    }

    if(right - left == s1.size()){
        bool isPermutation = true;
        for(int num : count){
            if(num != 0){
                isPermutation = false;
                break;
            }
        }
        if(isPermutation) return true;
    }
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidabooo";

    cout << checkInclusion(s1, s2) << endl;

    return 0;
}
#include<iostream>
#include<string>
#include<cctype>

using namespace std;
bool checkPalindrome(string s){
    int start=0;
    int end = s.length() - 1;
    while (start<end)
    {
       while (start<end && !isalnum(s[start]))
       {
         start++;
         while (start<end && !isalnum(s[end]))
         {
           end--;
           if(tolower(s[start]) != tolower(s[end])){
            return false;
           }
           start++;
           end--;
         }
         
       }
       
    }
    return true;
}
 
    int main(){
    string s;
    cout << " enter the value of string " << endl;
    cin >> s;

    cout << checkPalindrome(s) << endl;
    return 0;
}
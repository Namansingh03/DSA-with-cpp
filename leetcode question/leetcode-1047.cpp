#include<iostream>
#include<string>
using namespace std;
string removeDuplicates(string s){
    string result;

        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }

        return result;
    
}
 
    int main(){
    string s = "abbaca";
    
     cout << removeDuplicates(s) << endl;
    
    return 0;
}
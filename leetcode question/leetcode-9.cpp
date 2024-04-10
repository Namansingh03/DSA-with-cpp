#include<iostream>
using namespace std;
bool isPalindrome(int x){
     if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        cout << "x == reversed: " << (x == reversed) << endl;

        return x == reversed || x == reversed / 10;
}

 
    int main(){
    int n = 121;
    cout << isPalindrome(n) << endl;
    return 0;
}
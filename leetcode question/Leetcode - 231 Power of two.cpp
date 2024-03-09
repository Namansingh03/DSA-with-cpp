//? 231 - Power Of Two
#include<iostream>

using namespace std;

    int main(){
     int n;
     cout << "enter the value of n" << endl;
     cin >> n;


    if (n == 0)
            return 0;
        while (n != 1) {
            if (n % 2 != 0)
                return 0;
            n = n / 2;
        }
        return 1;
}

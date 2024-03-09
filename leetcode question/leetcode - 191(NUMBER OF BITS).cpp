//? 191 - Number Of Bits
#include<iostream>

using namespace std;

    int main(){
    int n = 11;
    int count = 0 ;
    while (n!=0)
    {
        //checking last bit
        if (n&1)
        {
           count++;
        }
        n = n>>1;
    }
    cout<<count<<endl;
    return 0;
}
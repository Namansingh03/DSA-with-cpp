//? 1009 compliment of Base Of 10
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary(int N){
     if(!N) return 1;

        vector<int> binary;
        while(N){
         binary.push_back(1 - N % 2);
         N /= 2;
        }  
        reverse(binary.begin(), binary.end());
        
        int result = 0;
        for(int b: binary) result = result * 2 + b;
        return result;
}
 
    int main(){
    cout << binary(5) << endl;
    return 0;
}
//? reverse a string
#include<iostream>
using namespace std;
void reverse(char str[] , int n){
    int s = 0;
    int e = n-1;
    while (s<e)
    {
        swap(str[s++],str[e--]);
    }
}
int getLength(char name[] ) {
    int count = 0;
    for (int i = 0; name[i] != '\0' ; i++)
    {
       count++;
    }
   return count ;
}
    int main(){
    char name[20];
    int len = getLength(name);

    cout<<"enter the value of string" << endl;
    cin >> name;
   
    cout << endl;
    cout << name << endl;
    
    reverse(name,len);

    cout << name << endl;
    
    return 0;
}
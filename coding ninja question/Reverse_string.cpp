#include<iostream>
#include<string>
using namespace std;
void reverse(string& str , int s , int e){
	if(s>e)
	return;

	swap(str[s++],str[e--]);
	reverse(str, s, e);
}

string reverseString(string str)
{
	reverse(str, 0, str.length()-1);
	return str;
}
 
    int main(){
    string str = "abcde";
    
    cout << reverseString(str) << endl;

    return 0;
}
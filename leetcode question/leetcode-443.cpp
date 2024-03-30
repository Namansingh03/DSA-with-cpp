#include<iostream>
#include<vector>
#include<string>
using namespace std;
int compress(vector<char> & chars){
    int index = 0;
    int i = 0;

    while( i < chars.size()){
        char currentChar = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == currentChar)
        {
            count++;
            i++;
        }
        
        chars[index++] = currentChar;

        if(count > 1){
            string countStr = to_string(count);
            for(int c: chars){
                chars[index++] = c;
            }
        }

    }
    return index;
}
 
    int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int newSize = compress(chars);
    
    cout << "Compressed Array: ";
    for (int i = 0; i < newSize; ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    
    return 0;
}
#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int>&inputStack,int count , int size){
        if(count == size/2){
            inputStack.pop();
            return;
        }
  
        int num = inputStack.top();
        inputStack.pop();

        solve(inputStack , count+1  , size);

        inputStack.push(num);
        
}

void deleteMiddle(stack<int>&inputStack, int N){
       int count = 0;
       solve(inputStack , count , N);
}

int main(){
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);

    int N = inputStack.size();

    deleteMiddle(inputStack, N);

    cout << "Stack after deleting the middle element: ";
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }

    return 0;
}
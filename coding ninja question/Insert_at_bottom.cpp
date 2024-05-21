#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int>& myStack , int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solve(myStack,x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack , x);
    return myStack;
}

int main(){
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack before pushing at bottom: ";
    stack<int> tempStack1 = myStack;
    while (!tempStack1.empty()) {
        cout << tempStack1.top() << " ";
        tempStack1.pop();
    }
    cout << endl;

    pushAtBottom(myStack, 0);

    cout << "Stack after pushing at bottom: ";
    stack<int> tempStack2 = myStack;
    while (!tempStack2.empty()) {
        cout << tempStack2.top() << " ";
        tempStack2.pop();
    }
    cout << endl;

    return 0;
}
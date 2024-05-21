#include<iostream>
#include<stack>

using namespace std;
void insertAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s,element);

    s.push(num);
}

void reverseStack(stack<int> &stack) {
   if(stack.empty()){
    return;
   }

   int num = stack.top();
   stack.pop();

   reverseStack(stack);

   insertAtBottom(stack, num);
}

int main() {
     
    stack<int> Stack;
    Stack.push(1);
    Stack.push(23);
    Stack.push(4);
    Stack.push(1);
    Stack.push(56);
    Stack.push(9);
    reverseStack(Stack);

    stack<int> tempStack2 = Stack;
    while (!tempStack2.empty()) {
        cout << tempStack2.top() << " ";
        tempStack2.pop();
    }
    return 0;
}
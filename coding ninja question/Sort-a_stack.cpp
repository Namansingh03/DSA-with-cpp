#include<iostream>
#include<stack>

using namespace std;
void sortAtInsert(stack<int>&s,int num){
     if(s.empty() || (!s.empty() && s.top() < num)){
          s.push(num);
          return;
     }
    
    int n = s.top();
    s.pop();

    sortAtInsert(s,num);

    s.push(n);
}

void sortStack(stack<int>&stack){
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortAtInsert(stack,num);
}

int main(){
    stack<int>s;
    s.push(7);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);
    s.push(0);
  
    sortStack(s);
   
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop()
    }

    return 0;
}
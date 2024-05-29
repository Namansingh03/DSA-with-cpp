#include<iostream>
#include<queue>

using namespace std;

class Queue {
    int *arr;
    int first;
    int rear;
    int size;

public:
    Queue() {
       size = 100001;
       arr = new int[size];
       first = 0;
       rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(first == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rear == size){
            return;
        }

        arr[rear] = data;
        rear ++;
    }

    int dequeue() {
       if(first == rear){
           return -1;
       }
      int ans = arr[first];
       arr[first] = -1;
       first++;
       if(first == rear){
           first = 0;
           rear = 0;
       }
       return ans;
    }

    int front() {
        if(first == rear){
            return -1;
        }

        return arr[first];
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element is: " << q.front() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    q.enqueue(30);
    q.enqueue(40);
    cout << "Front element is: " << q.front() << endl;
    cout << "Is queue empty? " << q.isEmpty() << endl;
    return 0;
}
#include <iostream>

using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Enqueues 'value' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            // Queue is full
            return false;
        } else if (front == -1) { // Insert the first element
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
    int dequeue() {
        if (front == -1) {
            // Queue is empty
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) { 
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return ans;
    }
};

int main() {
    CircularQueue q(5);

    cout << q.enqueue(10) << endl; // Output: 1
    cout << q.enqueue(20) << endl; // Output: 1
    cout << q.enqueue(30) << endl; // Output: 1
    cout << q.enqueue(40) << endl; // Output: 1
    cout << q.enqueue(50) << endl; // Output: 1
    cout << q.enqueue(60) << endl; // Output: 0 (Queue is full)

    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20
    cout << q.dequeue() << endl; // Output: 30

    cout << q.enqueue(60) << endl; // Output: 1
    cout << q.enqueue(70) << endl; // Output: 1

    cout << q.dequeue() << endl; // Output: 40
    cout << q.dequeue() << endl; // Output: 50
    cout << q.dequeue() << endl; // Output: 60
    cout << q.dequeue() << endl; // Output: 70
    cout << q.dequeue() << endl; // Output: -1 (Queue is empty)

    return 0;
}

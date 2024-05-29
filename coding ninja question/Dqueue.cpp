class Deque {
  int *arr;
  int front;
  int size;
  int rear;

public:
  // Initialize your data structure.
  Deque(int n) {
    size = n;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushFront(int x) {
    if (isFull()) {
      return false;
    }
    if (isEmpty()) {
      front = rear = 0;
    } else if (front == 0) {
      front = size - 1;
    } else {
      front--;
    }
    arr[front] = x;
    return true;
  }

  // Pushes 'X' in the back of the deque. Returns true if it gets pushed into
  // the deque, and false otherwise.
  bool pushRear(int x) {
    if (isFull()) {
      return false;
    }
    if (isEmpty()) {
      front = rear = 0;
    } else if (rear == size - 1) {
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = x;
    return true;
  }

  // Pops an element from the front of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popFront() {
    if (isEmpty()) {
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

  // Pops an element from the back of the deque. Returns -1 if the deque is
  // empty, otherwise returns the popped element.
  int popRear() {
    if (isEmpty()) {
      return -1;
    }

    int ans = arr[rear];
    arr[rear] = -1;

    if (front == rear) {
      front = rear = -1;
    } else if (rear == 0) {
      rear = size - 1;
    } else {
      rear--;
    }
    return ans;
  }

  // Gets the front element of the deque. Returns -1 if the deque is empty.
  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return arr[front];
  }

  // Gets the rear element of the deque. Returns -1 if the deque is empty.
  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return arr[rear];
  }

  // Checks if the deque is empty.
  bool isEmpty() {
    return front == -1;
  }

  // Checks if the deque is full.
  bool isFull() {
    return (front == (rear + 1) % size);
  }
};

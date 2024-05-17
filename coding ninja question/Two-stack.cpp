#include <iostream>

class TwoStack {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            std::cout << "Stack Overflow for stack 1\n";
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            std::cout << "Stack Overflow for stack 2\n";
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            std::cout << "Stack Underflow for stack 1\n";
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            std::cout << "Stack Underflow for stack 2\n";
            return -1;
        }
    }

    // Destructor to free allocated memory
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(10);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    std::cout << "Popped from stack 1: " << ts.pop1() << std::endl;  // 15
    std::cout << "Popped from stack 2: " << ts.pop2() << std::endl;  // 20
    std::cout << "Popped from stack 1: " << ts.pop1() << std::endl;  // 5
    std::cout << "Popped from stack 2: " << ts.pop2() << std::endl;  // 10

    return 0;
}

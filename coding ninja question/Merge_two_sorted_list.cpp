#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = nullptr;
        this->data = data;
    }

    ~Node() {
        if (next != nullptr) {
            delete next;
        }
    }
};

void solve(Node<int>*& first, Node<int>* second) {
    if (first == nullptr || second == nullptr) {
        return;
    }
    
    Node<int>* current1 = first;
    Node<int>* next1 = current1->next;
    Node<int>* current2 = second;
    Node<int>* next2 = current2->next;

    while (next1 != nullptr && current2 != nullptr) {
        if (current2->data >= current1->data && (current2->data <= next1->data)) {
            current1->next = current2;
            next2 = current2->next;
            current2->next = next1;
            current1 = current2;
            current2 = next2;
        } else {
            current1 = next1;
            next1 = next1->next;

            if (next1 == nullptr) {
                current1->next = current2;
                break;
            }
        }
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == nullptr) {
        return second;
    }

    if (second == nullptr) {
        return first;
    }

    if (first->data < second->data) {
        solve(first, second);
        return first;
    } else {
        solve(second, first);
        return second;
    }
}

int main() {
    Node<int>* firstList = new Node<int>(5);
    
    Node<int>* secondList = new Node<int>(-1);

    Node<int>* sortedList = sortTwoLists(firstList, secondList);

    Node<int>* current = sortedList;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    delete sortedList;

    return 0;
}

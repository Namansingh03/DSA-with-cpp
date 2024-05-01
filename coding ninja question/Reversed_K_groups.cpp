#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    
    int count = 0;
    while (curr != nullptr) {
        count++;
        if (count % k == 0) {
            prev = reverse(prev, curr->next);
            curr = prev->next;
        } else {
            curr = curr->next;
        }
    }
    
    return dummy->next;
}

Node* reverse(Node* prev, Node* next) {
    Node* last = prev->next;
    Node* curr = last->next;
    
    while (curr != next) {
        last->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = last->next;
    }
    
    return last;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3; // Reverse every 3 nodes
    cout << "Original Linked List: ";
    printList(head);

    // Reverse every k nodes
    head = reverseKGroup(head, k);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Test case
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

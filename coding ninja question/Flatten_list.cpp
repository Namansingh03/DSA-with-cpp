#include <iostream>

 class Node {
 public:
	int data;
	Node *next;
		Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge(Node* a, Node* b) 
{     
    if (a == NULL) 
        return b; 
  
    if (b == NULL) 
        return a; 
  
    Node* result; 
  
    if (a->data < b->data)  
    { 
        result = a; 
        result->child = merge(a->child, b); 
    } 
  
    else 
    { 
        result = b; 
        result->child = merge(a, b->child); 
    } 
    result->next = NULL; 
    return result; 
} 

Node* flattenLinkedList(Node* head) {
     
       if (head == NULL ||  
        head->next == NULL) 
        return head; 
  
    head->next = flattenLinkedList(head->next); 
  
    // Now merge 
    head = merge(head, head->next); 
  
    return head;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);

    head->child = new Node(2);
    head->child->next = new Node(4);

    head->next->child = new Node(6);

    Node* flattened = flattenLinkedList(head);

    printList(flattened); // Should print the flattened list in sorted order

    // Clean up memory (not shown here for brevity)
    return 0;
}

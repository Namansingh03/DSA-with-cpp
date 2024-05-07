#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *removeDuplicates(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *curr = head;
    while (curr != nullptr)
    {
        if ((curr->next != nullptr) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *toDelete = curr->next;
            delete (toDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> nullptr
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(5);

    // Print the original linked list
    cout << "Original linked list: ";
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Remove duplicates
    head = removeDuplicates(head);

    // Print the modified linked list
    cout << "Linked list after removing duplicates: ";
    curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}
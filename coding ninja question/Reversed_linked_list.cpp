#include <iostream>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    // Print the original linked list
    cout << "Original linked list: ";
    LinkedListNode<int> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << std::endl;

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed linked list: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Free memory
    while (head != nullptr)
    {
        LinkedListNode<int> *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
#include <iostream>
using namespace std;
//! floyd detect loop
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) { 
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL; 
            break;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head = new Node(2);
    head = new Node(3);
    head = new Node(4);
    head = new Node(5);
    head = new Node(6);

    if(removeLoop(head) != NULL){
        cout << "loop is present" << endl;
    }
    else{
        cout << "loop is not present" << endl;
    }
    return 0;
}
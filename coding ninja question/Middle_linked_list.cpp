#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findMiddle(Node *head) {
     if (head == NULL || head->next == NULL)
        return head;
      
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
 
    int main(){
    Node* head = new Node(5);
    head = new Node(2, head);
    head = new Node(21, head);
    head = new Node(3, head);
    head = new Node(8, head);

    cout << "All values: " << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    Node* middle = findMiddle(head);
    cout << "Middle value: " << middle->data << endl;

    cout << endl;
    return 0;
}
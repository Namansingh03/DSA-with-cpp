#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == nullptr)
        return right;
    
    if(right == nullptr)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != nullptr && right != nullptr) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != nullptr) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != nullptr) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}

node *mergeSort(node *head)
{
    if( head == nullptr || head -> next == nullptr ) {
        return head;
    }
    
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid -> next = nullptr;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    node* result = merge(left, right);
    
    return result;
}

void printList(node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(3);
    head->next = new node(1);
    head->next->next = new node(5);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(4);

    cout << "Unsorted list: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted list: ";
    printList(head);
    return 0;
}
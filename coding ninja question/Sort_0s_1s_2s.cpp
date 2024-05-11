#include <iostream>
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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if (temp->data == 2)
        {
                two++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);

    head = sortList(head);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
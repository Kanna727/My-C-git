#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, struct Node **tail, int d)
{
    struct Node *newN = new Node;
    newN->data = d;
    newN->next = NULL;
    if (*head == NULL)
    {
        *head = newN;
    }
    else
    {
        (*tail)->next = newN;
    }
    *tail = newN;
}

void printLL(Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
        return;
    //cout << "Linked List entered: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void sw(Node *&a, Node *&b)
{
    Node *temp = a;
    a = b;
    b = temp;
}

int swap(struct Node **head, int a, int b)
{
    struct Node **preva = NULL;
    struct Node **prevb = NULL;
    //struct Node *curr = *head;
    if (*head == NULL)
        return 0;
    if (a == b)
        return 1;
    while (*head != NULL)
    {
        if ((*head)->data == a)
            preva = head;
        else if ((*head)->data == b)
            prevb = head;
        head = &((*head)->next);
    }
    if (preva && prevb)
    {
        sw(*preva, *prevb);
        sw((*preva)->next, (*prevb)->next);
        return 2;
    }
    else if(!preva) return 3;
    else if(!prevb) return 4;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    cout << "Enter Each element of linked list: (Press 'done' to stop inserting)" << endl;
    string i;
    while (cin >> i && i != "done")
    {
        insert(&head, &tail, stoi(i));
    }
    cout<<"Entered Linked List is: ";
    printLL(head);
    cout << "Enter the 2 elements to swap: ";
    int a, b;
    cin >> a;
    cin >> b;
    switch (swap(&head, a, b))
    {
    case 0:
        cout << "Linked List is empty" << endl;
        break;
    case 1:
        cout << "Entered elements to swap are same";
        break;
    case 2:
        cout<<"Linked List after swap: ";
        printLL(head);
        break;
    case 3:
        cout<<"The first element " << a << " is not in Linked List"<<endl;
        break;
    case 4:
        cout<<"The second element "<<b<<" is not in Linked List"<<endl;
        break;
    }
}
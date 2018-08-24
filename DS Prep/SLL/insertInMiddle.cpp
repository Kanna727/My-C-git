#include<bits/stdc++.h>
using namespace std;


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


//Structure of the Node of the linked list is as
struct Node {
	int data;
	Node* next;
};
// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
    int count = 0;
    Node *start = head,*mid = head, *temp;
    Node *newNode = new Node;
    newNode->data = x;
    if(head == NULL) {
        return head;
    }
    else {
        while(head != NULL) {
            if(count > 1 && count & 1) {
                mid = mid->next;
            }
            count++;
            head = head->next;
        }
        if (count != 1) {
            if (count & 1) {
                mid = mid -> next;
            }
            if (mid != NULL) {
                temp = mid->next;
                mid->next = newNode;
                newNode -> next = temp;
            }
        } else {
            mid -> next =  newNode;
        }
        return start;
    }
}
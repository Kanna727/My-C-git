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
// Should reverse list and return new head.
Node* reverse(Node *head)
{
    int count = 0;
    Node *start = head;
    while(head != NULL) {
        count++;
        if(count >2){
            break;
        }
        head = head -> next;
    }
    if(count == 1) {
        return start;
    }
    else if(count == 2){
        Node *ptr1 = start;
    Node *ptr2 = ptr1 -> next;
    ptr1 -> next = NULL;
    ptr2 -> next = ptr1;
    return ptr2;
    }
    else {
        Node *ptr1 = start;
    Node *ptr2 = ptr1 -> next;
    Node *ptr3 = ptr2-> next;
    ptr1 ->next = NULL;
    ptr2 -> next = ptr1;
    while(ptr3!= NULL) {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3 -> next;
        ptr2->next = ptr1;
    }
    return ptr2;
    }
  // Your code here
}
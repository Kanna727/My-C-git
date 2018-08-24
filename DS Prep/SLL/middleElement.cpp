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
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    int count = 0;
    Node *mid = head;
    while(head != NULL) {
        if(count & 1){
            mid = mid -> next;
        }
        count++;
        head =  head->next;
    }
    if(mid!=NULL){
        return mid->data;
    }
    else{
        return 0;
    }
   // Your code here
}
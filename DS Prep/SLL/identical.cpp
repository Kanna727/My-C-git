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
// Complete this function
// return true if two list are identical else return false
bool areIdentical(struct Node *head1, struct Node *head2)
{
    bool flag = true;
    while(head1!=NULL && head2!=NULL){
        if(head1->data != head2->data || (head1->next !=NULL ^ head2->next != NULL)){
            flag = false;
            break;
        }
        head1 = head1->next;
        head2= head2->next;
    }
    return flag;
    // Code here
}
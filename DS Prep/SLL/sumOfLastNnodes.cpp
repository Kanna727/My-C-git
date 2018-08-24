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
// your task is to complete this function 
// function should return sum of last n nodes
int sumOfLastN_Nodes(struct Node* head, int n)
{
    int count = 0, i = 0, res = 0;
    vector<int> arr;
    while(head != NULL) {
        count++;
        arr.push_back(head->data);
        //cout<<arr[n]<<endl;
        if(count > n) {
            
            arr.erase(arr.begin());
        }
        head = head->next;
    }
    for(int j = 0; j < n; j++) {
        //cout<<arr[i]<< endl;
        res += arr[j];
    }
    return res;
      // Code here
}
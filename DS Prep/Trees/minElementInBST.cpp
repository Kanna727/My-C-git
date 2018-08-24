#include<bits/stdc++.h>
using namespace std;

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
//Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// your task is to complete the below function
int minValue(Node* root)
{
    if(!root) return -1;
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
    // Code here
}
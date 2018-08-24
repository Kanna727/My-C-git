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
// Function should return the sum of all the elements
// of the binary tree
long int sumBT(Node* root)
{
    long int sum = 0;
    if(!root) return 0;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node* node = q.front();
        sum += node->data;
        q.pop();
        
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
    return sum;
    // Code here
}
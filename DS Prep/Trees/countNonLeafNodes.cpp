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
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
int countNonLeafNodes(Node* root)
{
    int tcount = 0, lcount =0;
    if(!root) return 0;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node* node = q.front();
        tcount++;
        q.pop();
        
        if(node->left !=NULL) q.push(node->left);
        if(node->right !=NULL) q.push(node->right);
        if(node->left == NULL && node->right == NULL) lcount++;
    }
    return tcount - lcount;
    // Code here
}
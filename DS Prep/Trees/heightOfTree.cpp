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
/* Computes the height of binary tree with given root.  */
int height(Node* node)
{
    if(node == NULL) return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    if(lh>rh) return lh + 1;
    else return rh+1;
   // Your code here
}
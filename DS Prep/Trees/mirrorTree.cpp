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
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
    if(!node) return;
    
    struct Node* temp;
    
    mirror(node->left);
    mirror(node->right);
    
    temp = node->left;
    node->left = node->right;
    node->right = temp;
     // Your Code Here
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
}

void reverseOrderIter(Node* root)
{
    stack <Node *> S;
    queue <Node *> Q;
    Q.push(root);
 
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}

int main()
{
    int n;
    std::cout << "Enter no of node sin tree (except root node): ";
    cin>>n;

    map<int, Node*> m;
    struct Node* root = NULL;
    struct Node *parent, *child;
    while(n--){
        int p,c;
        char lr;
        cin>>p>>c>>lr;
        if(m.find(p) == m.end()){
            parent = newNode(p);
            m[p] = parent;
            if(!root) root = parent;
        } else{
            parent = m[p];
        }
        child = newNode(c);
        lr == 'L' ? parent->left = child : parent->right = child;
        m[c] = child;
    }
    
    reverseOrderIter(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
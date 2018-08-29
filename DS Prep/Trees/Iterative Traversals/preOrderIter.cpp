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

void preOrderIter(struct Node* root){
    if(!root) return;

    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();

        cout<< root->data<< " ";
        if(root->right) s.push(root->right); 
        if(root->left) s.push(root->left);
    }
}

int main()
{
    int n;
    std::cout << "Enter no of nodes in tree (except root): ";
    cin>>n;

    map<int, Node*> m;
    struct Node* root = NULL;
    struct Node *parent, *child;
    while(n--){
        int p, c;
        char lr;
        cin>>p>>c>>lr;
        if(m.find(p) == m.end()){
            parent = newNode(p);
            m[p] = parent;
            if(root == NULL) root= parent;
        } else {
            parent = m[p];
        }
        child = newNode(c);
        lr == 'L' ? parent->left = child : parent->right = child;
        m[c] = child;
    }
    
    preOrderIter(root);
    cout<<endl;

    system("pause");
    return 0;
}
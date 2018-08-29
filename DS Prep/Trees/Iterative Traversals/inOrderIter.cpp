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
    return node;
}

void inOrderIter(struct Node* root){
    if(!root) return;

    struct Node* curr = root;
    stack<Node*> s;

    while(curr||!s.empty()){
        while(curr){
            s.push(curr);

            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

int main()
{
    int n;
    std::cout << "Enter no of nodes in tree: ";
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
            if(root == NULL) root = parent;
        } else {
            parent = m[p];
        }
        child = newNode(c);
        lr == 'L' ? parent->left = child : parent->right = child;
        m[c] = child;
    }

    inOrderIter(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
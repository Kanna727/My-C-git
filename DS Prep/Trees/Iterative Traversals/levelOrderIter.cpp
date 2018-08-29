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

void levelOrderIter(struct Node* root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        root = q.front();
        q.pop();

        cout<<root->data<<" ";

        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
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
    
    levelOrderIter(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
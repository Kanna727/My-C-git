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

void topView(struct Node *root)
{
    if (root == NULL)
        return;
 
    unordered_map<int, int> m;
    queue<pair<Node*, int>> q;
 
    // push node and horizontal distance to queue
    q.push(make_pair(root, 0));
    
    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        Node *n = p.first;
        int val = p.second;
        q.pop();
         
        // if horizontal value is not in the hashmap 
        // that means it is the first value with that
        // horizontal distance so print it and store 
        // this value in hashmap
        if (m.find(val)==m.end())
        {
            m[val] = n->data;
            printf("%d ", n->data);
        }
         
        if (n->left != NULL)
            q.push(make_pair(n->left, val-1));
         
        if (n->right != NULL)
            q.push(make_pair(n->right, val+1));
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
    
    topView(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
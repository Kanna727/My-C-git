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

void diagonalIter(Node* root)
{
    // base case
    if (root == NULL)
        return;
 
    // inbuilt queue of Treenode
    queue<Node*> q;
 
    // push root
    q.push(root);
 
    // push delimiter
    q.push(NULL);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        // if current is delimiter then insert another
        // for next diagonal and cout nextline
        if (temp == NULL) {
 
            // if queue is empty return
            if (q.empty())
                return;
 
            // output nextline
            cout << endl;
 
            // push delimiter again
            q.push(NULL);
        }
        else {
            while (temp) {
                cout << temp->data << " ";
 
                // if left child is present 
                // push into queue
                if (temp->left)
                    q.push(temp->left);
 
                // current equals to right child
                temp = temp->right;
            }
        }
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
    
    diagonalIter(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
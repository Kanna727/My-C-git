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

void printVerticalOrder(Node* root)
{
    // Base case
    if (!root)
        return;
 
    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));
 
     while (!que.empty())
     {
        // pop from queue front
        pair<Node *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data in vector of hash
        m[hd].push_back(node->data);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd-1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd+1));
    }
 
    // Traverse the map and print nodes at
    // every horigontal distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
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
    
    printVerticalOrder(root);
    cout<<endl;
    
    system("pause");
    return 0;
}
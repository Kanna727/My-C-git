#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postOrderIter(struct Node *root)
{
    if (!root)
        return;

    stack<Node *> s;
    Node *curr = root;

    while (curr || !s.empty())
    {

        while (curr)
        {
            if (curr->right)
                s.push(curr->right);
            s.push(curr);

            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        if (!s.empty())
        {
            if (curr->right && s.top() == curr->right)
            {
                s.pop();
                s.push(curr);
                curr = curr->right;
            }
            else
            {
                std::cout << curr->data << " ";
                curr = NULL;
            }
        }
        else
        {
            std::cout << curr->data << " ";
            curr = NULL;
        }
    }
}

int main()
{
    int n;
    std::cout << "Enter no of nodes in tree: ";
    cin >> n;

    map<int, Node *> m;
    struct Node *root = NULL;
    struct Node *parent;
    struct Node *child;

    while (n--)
    {
        int p, c;
        char lr;
        cin >> p >> c >> lr;
        if (m.find(p) == m.end())
        {
            parent = newNode(p);
            m[p] = parent;
            if (!root)
                root = parent;
        }
        else
        {
            parent = m[p];
        }
        child = newNode(c);
        lr == 'L' ? parent->left = child : parent->right = child;
        m[c] = child;
    }

    postOrderIter(root);

    cout<<endl;

    system("pause");
    return 0;
}
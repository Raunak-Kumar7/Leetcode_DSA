// Problem is same as Level Order Traversal LC 102
Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *head = root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *n = q.front();
            q.pop();
            if (nodeCount - 1 > 0)
            {
                n->next = q.front();
            }
            else
            {
                n->next = nullptr;
            }
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
            nodeCount--;
        }
    }
    return root;
}

// Youtube link: https://www.youtube.com/watch?v=U4hFQCa1Cq0&t=329s

// Method 1 : BFS Level Order Traversal O(N) but space O(max nodes in a level) --> O(N/2)

// Method 2 : DFS Since it is a PERFECT BINARY TREE , the following approach works

// Method 3 : BFS without queue , using currlevel and nxt level pointer (done with this method --> MOST OPTIMAL METHOD)
// Works because PERFECT Binary Tree

Node *connect(Node *root)
{
    if (!root)
        return root;
    Node *curr = root;
    Node *nxt = root->left;
    while (nxt)
    {
        while (curr)
        {
            curr->left->next = curr->right;
            if (curr->next)
                curr->right->next = curr->next->left;
            else
                curr->right->next = nullptr;
            curr = curr->next;
        }

        curr = nxt;
        nxt = nxt->left;
    }
    return root;
}
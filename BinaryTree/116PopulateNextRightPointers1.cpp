//Problem is same as Level Order Traversal LC 102
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
        Node* head = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int nodeCount = q.size();
            while(nodeCount>0)
            {
                Node* n = q.front();
                q.pop();
                if(nodeCount-1>0)
                {
                    n->next = q.front();
                }
                else
                {
                    n->next = nullptr;
                }
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                nodeCount--;
            }
        }
        return root;
    }
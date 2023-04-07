//Using Level Order Traversal --> O(N) queue size in WC
vector<int> leftView(Node *root)
{
    //Level Order Traversal
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    if(root==nullptr) 
        return ans;
    while(!q.empty())
    {
        int countNodes = q.size();
        int i=0;
        while(countNodes>0)
        {
            Node* n = q.front();
            q.pop();
            if(i==0) //picking first node in each level
                ans.push_back(n->data);
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            countNodes--;
            i++;
        }
    }
    return ans;
}
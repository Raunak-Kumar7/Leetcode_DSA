// Level Order traversal give MLE on LC but AC on CN
//  Using Level Order Traversal
string serialize(TreeNode *root)
{
    string ans = "";
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            TreeNode *n = q.front();
            q.pop();

            if (n)
            {
                ans = ans + to_string(n->val) + ",";
                q.push(n->left);
                q.push(n->right);
            }
            else
            {
                ans = ans + "#,";
            }

            countNodes--;
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
// Using String stream --> treats chars in string as objects
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *n = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
            n->left = nullptr;
        else
        {
            n->left = new TreeNode(stoi(str));
            q.push(n->left);
        }

        getline(s, str, ',');
        if (str == "#")
            n->right = nullptr;
        else
        {
            n->right = new TreeNode(stoi(str));
            q.push(n->right);
        }
    }
    return root;
}
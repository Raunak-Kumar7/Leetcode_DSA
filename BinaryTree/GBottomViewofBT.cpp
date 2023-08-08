// same as top view, only diff is keep updating the map
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    queue<pair<int, Node *>> q;
    q.push({0, root});
    map<int, Node *> mp;

    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<int, Node *> node = q.front();
            q.pop();
            int lvl = node.first;
            Node *n = node.second;

            mp[lvl] = n; // keep updating

            if (n->left)
                q.push({lvl - 1, n->left});
            if (n->right)
                q.push({lvl + 1, n->right});
            countNodes--;
        }
    }
    for (auto it : mp)
        ans.push_back(it.second->data);

    return ans;
}
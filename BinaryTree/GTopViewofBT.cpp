// Level Order traversal -- stored with vertical levels (updated only once for TOP)
// use map to store {level,node}
vector<int> topView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, Node *> mp; // to store for each level map-->sorted

    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<Node *, int> node = q.front();
            q.pop();
            int lvl = node.second;
            Node *n = node.first;
            if (mp.find(lvl) == mp.end())
            {
                mp[lvl] = n;
            }
            if (n->left)
                q.push({n->left, lvl - 1});
            if (n->right)
                q.push({n->right, lvl + 1});
            countNodes--;
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second->data);
    }
    return ans;
}
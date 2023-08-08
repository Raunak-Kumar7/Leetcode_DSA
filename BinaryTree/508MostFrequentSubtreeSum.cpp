// Postorder Traversal
// find sum of left and right subtree first

int f(TreeNode *root, unordered_map<int, int> &mp)
{
    if (root == nullptr)
        return 0;

    int l = f(root->left, mp);
    int r = f(root->right, mp);
    mp[l + r + root->val]++;
    return l + r + root->val;
}
vector<int> findFrequentTreeSum(TreeNode *root)
{
    unordered_map<int, int> mp;
    f(root, mp);
    int maxi = INT_MIN;
    for (auto it : mp)
        maxi = max(maxi, it.second);
    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second == maxi)
            ans.push_back(it.first);
    }
    return ans;
}
// Postorder is basically reversed preorder but the difference is after root right comes in postorder
// Similar approach as Inorder and preorder, only diff will be order of calls right first then left
TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &idx, int left, int right, unordered_map<int, int> &mp)
{
    if (left > right)
        return nullptr;

    TreeNode *root = new TreeNode(postorder[idx]);

    int f = mp[postorder[idx]];
    idx--;
    // right first then left
    root->right = build(inorder, postorder, idx, f + 1, right, mp);
    root->left = build(inorder, postorder, idx, left, f - 1, mp);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // map to have quick search in inorder array
    unordered_map<int, int> mp;
    int k = 0;
    for (auto it : inorder)
    {
        mp[it] = k;
        k++;
    }
    int n = inorder.size();
    int idx = n - 1;

    return build(inorder, postorder, idx, 0, n - 1, mp);
}
// only idx is passed with ref
// new parameters
//  idx -> in preorder array
//  left and right of inorder array
// mp

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &idx, int left, int right, unordered_map<int, int> &mp)
{
    if (left > right)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[idx]);
    int f = mp[preorder[idx]];
    idx++;
    if (left == right)
        return root;
    root->left = build(preorder, inorder, idx, left, f - 1, mp);
    root->right = build(preorder, inorder, idx, f + 1, right, mp);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp; // to optimise searching of root in inorder vec
    int k = 0;
    for (auto it : inorder)
    {
        mp[it] = k;
        k++;
    }
    int n = inorder.size();
    int idx = 0;
    TreeNode *root = build(preorder, inorder, idx, 0, n - 1, mp);
    return root;
}
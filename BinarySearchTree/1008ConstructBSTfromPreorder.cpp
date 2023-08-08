// METHOD 1: APPLY INSERT OPERATION FOR ALL NODES IN THE PREORDER

// METHOD 2: CREATE ANOTHER ARRAY INORDER --> CREATE BT USING PREORDER AND INDORDER

// METHOD 3 : USING 1 UPPER BOUND
//  if we go left to create a node its ub will be root
// if we go right to create a node its ub will be root's ub
TreeNode *f(vector<int> &preorder, int &idx, int &ub)
{
    if (idx == preorder.size() || preorder[idx] > ub) // 1 extra bc if UB voilation
        return nullptr;

    TreeNode *root = new TreeNode(preorder[idx]);
    idx++;

    root->left = f(preorder, idx, root->val);
    root->right = f(preorder, idx, ub);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int ub = INT_MAX;
    int idx = 0;
    return f(preorder, idx, ub);
}
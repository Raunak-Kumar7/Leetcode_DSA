// checking using ub and lb
// if we go right to check a node , it should satisfy both the lb and ub conditions and its lb = root and ub same as root's ub
// if we go left to check a node, it should satisfy both the lb and rb conditions and its lb = lb of root and its rb = root

// make sure to use LONG_MIN and LONG_MAX for the lb and ub tc  [2147483647]
bool valid(TreeNode *root, long min, long max)
{
    if (root == nullptr)
        return true;
    return (root->val > min && root->val < max) && valid(root->left, min, root->val) && valid(root->right, root->val, max);
}
bool isValidBST(TreeNode *root)
{
    return valid(root, LONG_MIN, LONG_MAX);
    // USE LONG_MIN AND LONG_MAX else cases where node values are equal to INT_MIN or INT_MAX fail
}
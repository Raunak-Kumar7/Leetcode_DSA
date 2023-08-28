bool check(TreeNode *A, TreeNode *B)
{
    if (A == nullptr && B == nullptr)
        return true;
    if (A == nullptr || B == nullptr)
        return false;

    return (A->val == B->val && check(A->left, B->right) && check(A->right, B->left));
}
bool isSymmetric(TreeNode *root)
{
    if (root->left == nullptr && root->right == nullptr) // single node
        return true;
    return check(root->left, root->right);
}
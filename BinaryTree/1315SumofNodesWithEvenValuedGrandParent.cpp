// We can do any traversal(IN,PRE,POST)
void f(TreeNode *root, int &sum)
{
    // write this in order else it will access null node
    if (root == nullptr)
        return;
    if (root->val % 2 == 0)
    {
        int a = 0, b = 0, c = 0, d = 0;
        if (root->left && root->left->left)
            a = root->left->left->val;
        if (root->left && root->left->right)
            b = root->left->right->val;
        if (root->right && root->right->left)
            c = root->right->left->val;
        if (root->right && root->right->right)
            d = root->right->right->val;
        sum += a + b + c + d;
    }
    f(root->left, sum);
    f(root->right, sum);
}
int sumEvenGrandparent(TreeNode *root)
{
    int sum = 0;
    f(root, sum);
    return sum;
}
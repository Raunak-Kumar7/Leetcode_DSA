int isSumProperty(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 1;

    else
    {
        int sum = 0;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;
        return ((sum == root->data) && isSumProperty(root->left) && isSumProperty(root->right));
    }
}
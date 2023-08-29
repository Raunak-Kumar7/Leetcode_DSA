// S1: Search the key recursively
// S2: when found make 3 cases
//  if no left child delete root and return root->right
//  if no right child delete root and return root->left
// if both left and right exist search in right subtree the leftmost node and replace it with it
TreeNode *minValue(TreeNode *root)
{

    TreeNode *ans = root;
    while (root->left)
    {
        root = root->left;
        ans = root;
    }
    return ans;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);

    else // node forund
    {
        if (root->left == nullptr) // only right child
        {
            TreeNode *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == nullptr) // only left child
        {
            TreeNode *temp = root->left;
            delete (root);
            return temp;
        }
        else // both left and right child --> replace with smallest value in right subtree
        {
            TreeNode *n = minValue(root->right);
            root->val = n->val;
            root->right = deleteNode(root->right, n->val);
        }
    }
    return root;
}
// we want Preorder
// store right subtree temporarily
// copy left subtree to right
// left == nullptr
// add back the right subtree to right most node of the attached left subtree
void flatten(TreeNode *root)
{
    while (root)
    {
        if (root->left) // slight optimisation
        {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode *t2 = root;
            while (t2 && t2->right)
                t2 = t2->right;
            t2->right = temp;
        }
        root = root->right;
    }
}

// Methods from striver(see video)
// Recursive
// Iterative
// Morris Traversal
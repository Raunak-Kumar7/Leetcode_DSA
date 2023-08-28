// S1: While going down if sum of both children < root
//  --> make both the children == root
//  else if sum of both children >= root
// make root = sum of children
// S2: While going up always update the root by sum of children
void changeTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return;

    int l = 0;
    int r = 0;
    if (root->left)
        l = root->left->data;
    if (root->right)
        r = root->right->data;
    int sum = l + r;
    if (sum < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else
    {
        root->data = sum;
    }

    changeTree(root->left);
    changeTree(root->right);

    // S2: Backtraing --> update root;
    int l2 = 0;
    int r2 = 0;
    if (root->left)
        l = root->left->data;
    if (root->right)
        r = root->right->data;
    if (root->right || root->left) // update if not a leaf
        root->data = l + r;
}
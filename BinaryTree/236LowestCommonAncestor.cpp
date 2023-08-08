// Method 1:
// Root to Node Path for both Nodes
// Pick the last common node in both the paths
bool rootToNode(TreeNode *root, TreeNode *n, vector<TreeNode *> &ans)
{
    if (root == nullptr)
    {
        return false;
    }

    ans.push_back(root);
    if (root == n)
        return true;
    if (rootToNode(root->left, n, ans) || rootToNode(root->right, n, ans)) // if found anywhere keep returning true
        return true;
    else
    {
        ans.pop_back();
        return false;
    }
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> p1;
    rootToNode(root, p, p1);
    vector<TreeNode *> p2;
    rootToNode(root, q, p2);

    int l1 = p1.size();
    int l2 = p2.size();
    int i = 0, j = 0;
    TreeNode *ans = root;
    while (i < l1 && j < l2)
    {
        if (p1[i] == p2[j])
            ans = p1[i];
        else
            break;
        i++;
        j++;
    }
    return ans;
}

// Optimal
// Inorder Traversal

//     we can find the LCA of 2 given nodes from
//     i) Left subtree or in
//     ii)Right subtree,
//     if not in both the subtrees then root will be the  LCA.

// Approach
//     1. If root is null or if root is x or if root is y then return root
//     2.  Made a recursion call for both
//     3. If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
//     4. If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
//     5.If both left & right calls give values (not null)  that means the root is the LCA.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (!left) // neither p nor q found in left
        return right;
    else if (!right) // neither p nor q found in right
        return left;
    else // one node in left and one node in right --> root is LCA
        return root;
}
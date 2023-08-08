// 2 methods:
//  1. store root to node paths for the nodes and pick the last common
//  2. lca of a bt if(!left) return right if(!right) return left else return root

// Optimised Method : for BST
// As big no.s are on right and smaller on left , the root where one node is smaller and other is greater is the lca
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return root;
    if (p->val > q->val)
        swap(p, q);
    // p always has smaller value
    while (root)
    {
        if (root->val >= p->val && root->val <= q->val)
            return root;
        else if (root->val < p->val && root->val < q->val)
            root = root->right;
        else
            root = root->left;
    }
    return nullptr;
}
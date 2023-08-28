/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // Brute: For any trvaersal --> if we calc lh and rh for each node lh + rh - 1
    // Optimal: we dont need to calc lh , rh again and again --> we can use postorder traversal so that lh and rh is first calculated then we make calculations for the root
    // Brute
    int f(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        int lh = 0, rh = 0;
        lh = f(root->left, maxi);
        rh = f(root->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        f(root, maxi);
        return maxi;
    }
};
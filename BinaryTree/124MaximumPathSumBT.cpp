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
    // postorder --> height approach
    int f(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        // never considering negative sums --> so return 0 --> means not including if -ve
        int lsum = max(0, f(root->left, maxi));
        int rsum = max(0, f(root->right, maxi));

        maxi = max(maxi, lsum + rsum + root->val); // for each node we calc path sum as max from left and max from right and node->val --> and take maxi
        return root->val + max(lsum, rsum);        // for nodes above it we wont take both lsum or rsum becuase we cant go on 2 paths, so we tak emax of both
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};
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
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int lheight=height(root->left);
        int rheight=height(root->right);
        return max(lheight,rheight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lh,rh=0;
        int lDiameter = diameterOfBinaryTree(root->left);
        int rDiameter = diameterOfBinaryTree(root->right);
        int currDiameter=height(root->left)+height(root->right);
        return max(currDiameter,max(lDiameter,rDiameter));
    }
};
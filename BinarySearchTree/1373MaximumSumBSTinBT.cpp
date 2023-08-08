// same question as Max size BST in BT , just pass a maxi variable to keep track of maximum sum in all calls , update if bst
// Postorder Traversal
// need to maintain 3 values for each node so create a diff class

class NodeValue
{
public:
    int maxNode, minNode;
    long long maxSum;
    NodeValue(int mx, int mn, long long sum)
    {
        maxNode = mx;
        minNode = mn;
        maxSum = sum;
    }
};

class Solution
{
public:
    NodeValue maxBSTHelper(TreeNode *root, long long &maxi)
    {
        if (root == nullptr)
            return NodeValue(INT_MIN, INT_MAX, 0);

        auto left = maxBSTHelper(root->left, maxi);
        auto right = maxBSTHelper(root->right, maxi);

        if (root->val > left.maxNode && root->val < right.minNode)
        {
            maxi = max(maxi, left.maxSum + right.maxSum + root->val);
            return NodeValue(max(right.maxNode, root->val), min(left.minNode, root->val), left.maxSum + right.maxSum + root->val);
        }
        else
        {
            return NodeValue(INT_MAX, INT_MIN, max(left.maxSum, right.maxSum));
        }
    }
    int maxSumBST(TreeNode *root)
    {
        long long maxi = 0;
        maxBSTHelper(root, maxi);
        return maxi;
    }
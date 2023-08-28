// Keep storing path in an array and do a simple traversal
// dfs pop when false

// Bool signifies if we have reached that node or not
bool f(TreeNode *root, int B, vector<int> &ans)
{
    if (root == nullptr)
        return false;

    ans.push_back(root->val);
    if (root->val == B)
        return true;

    if (f(root->left, B, ans) || f(root->right, B, ans)) // if we found the node in any of the calls we dont need to make any left or right calls --> just keep returning true
        return true;
    else
    {
        ans.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode *root, int B)
{
    vector<int> ans;
    f(root, B, ans);
    return ans;
}
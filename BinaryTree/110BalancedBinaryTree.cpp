// Approach 1: Calc Height for Every node O(n^2) (every node O(N) * height O(N))
// S1 : Calc lh, rh and check if node is balanced
// S2 : Go to every node to do the same (We can do this in any order i.e. Pre, In, Post)

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right); // S2
}

// HEIGHT Function approach
// Approach 2: We were going to every node and calcualting its height
// but this calcualting height part again and again can be avoided
// While we calcluate height we get heights from both sides i.e. lh and rh, at that momemt itself we can compare if its balanced or not
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    if (lh == -1 || rh == -1)
        return -1; // if any 1 is balanced then also Tree is Unbalanced
    if (abs(lh - rh) > 1)
        return -1; // 2 extra cond to check if balanced

    return 1 + max(lh, rh);
}
// If we get -1 means unbalanced, if we get a height means balanced
bool isBalanced(TreeNode *root)
{
    return height(root) == -1 ? false : true;
}

// CLEANER AND EASIER APPROACH 2
// USE an ans variable to store T/F
int f(TreeNode *root, bool &ans)
{
    if (root == nullptr)
        return 0;
    int lh = f(root->left, ans);
    int rh = f(root->right, ans);
    if (abs(lh - rh) > 1)
    {
        ans = false;
    }
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    bool ans = true;
    f(root, ans);
    return ans;
}
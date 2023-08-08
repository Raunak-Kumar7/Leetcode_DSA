// Morris Traversal
// Code Similar to Inorder Traversal
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == nullptr)
            {
                prev->right = curr;
                preorder.push_back(curr->val); // preorder root first then left
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;

                curr = curr->right;
            }
        }
    }
    return preorder;
}

// Recursive Approach
class Solution
{
public:
    void preorder(vector<int> &ans, TreeNode *root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorder(ans, root->left);
        preorder(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(ans, root);
        return ans;
    }
};

// Instead of writing a separate Function , we can also declare the ans vector globally, and implement in the same function

// Iterative Approach:
// we use STACK to replace Recursive Stack

// ROOT  LEFT RIGHT
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *n = st.top();
        st.pop();
        ans.push_back(n->val);
        // Push Right first then left becuase LIFO so we want left to be on top to proccess it first
        if (n->right)
            st.push(n->right);
        if (n->left)
            st.push(n->left);
    }
    return ans;
}

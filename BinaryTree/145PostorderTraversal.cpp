class Solution
{
public:
    // Morris Order Traversal
    // Step1 -- Same as preorder only swap left and right everywhere in preorder code
    // Sttep2 -- At last reverse the Vector
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->right == NULL)
            {
                postorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                TreeNode *prev = cur->right;
                while (prev->left && prev->left != cur)
                {
                    prev = prev->left;
                }
                if (prev->left == NULL)
                {
                    prev->left = cur;
                    postorder.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    prev->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};

class Solution
{
public:
    void postorder(vector<int> &ans, TreeNode *root)
    {
        if (root == nullptr)
            return;
        postorder(ans, root->left);
        postorder(ans, root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(ans, root);
        return ans;
    }
};

// Instead of writing a separate Function , we can also declare the ans vector globally, and implement in the same function

// Iterative
vector<int> postOrder(Node *root)
{
    // Writing my own 1 stack derived from 2 stack itself
    // Write same as preorder travesal (EXCEPT LEFT THEN RIGHT);
    // at last reverse the ans vector ----> second vector is used to reverse the ans nothing else
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *n = st.top();
        st.pop();
        ans.push_back(n->data);
        if (n->left)
            st.push(n->left);
        if (n->right)
            st.push(n->right);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
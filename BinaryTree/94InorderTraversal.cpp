// Morris Traversal(Threaded Binary Tree)
// T.C. O(amortized N) S.C O(1)
vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    vector<int> inorder;

    while (curr)
    {
        if (!curr->left)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // left exists --> 1st make threaded connection
            // Move to rightmost of left node
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr) // prev->right!=nullptr condition is to stop the loop when there is no more right child left, prev->right!=curr condition is to stop the loop at rightmost child on left subtree, when the threaded edge already exists , so that its stops there only and is not trapped in a cycle
            {
                prev = prev->right;
            }

            if (prev->right == nullptr) // if no thread exists --> make the thread
            {
                prev->right = curr;
                curr = curr->left; // then move to left subtree
            }
            else // if thread already exists means we are again coming from root to left and rightmost and threaded connection is already there --> which means left subtree is traversed
            {
                prev->right = nullptr;        // cut the thread
                inorder.push_back(curr->val); // add root to ans as left subtree is completed
                curr = curr->right;           // now go to right substree left root right
            }
        }
    }
    return inorder;
}

// Recursiove Solution

class Solution
{
public:
    void inorder(vector<int> &ans, TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
};

// Instead of writing a separate Function , we can also declare the ans vector globally, and implement in the same function

// Iterative
vector<int> inOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *n = root;
    st.push(n);
    while (!st.empty())
    {
        while (n->left)
        {
            st.push(n->left);
            n = n->left;
        }
        Node *node = st.top();
        st.pop();
        ans.push_back(node->data);
        if (node->right)
        {
            node = node->right;
            while (node)
            {
                st.push(node);
                node = node->left;
            }
        }
    }
    return ans;
}

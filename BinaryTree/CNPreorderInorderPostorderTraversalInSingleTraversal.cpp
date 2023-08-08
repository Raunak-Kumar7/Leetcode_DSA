// Iterative Stack{TreeNode*,int}
// if num = 1 --> preorder add
//  else if num = 2 -> inorder add
//  else if num = 3 --> postorder add
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    if (root == nullptr)
        return ans;

    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        int num = st.top().second;
        BinaryTreeNode<int> *n = st.top().first;
        if (num == 1)
        {
            preorder.push_back(n->data);
            ++st.top().second;
            if (n->left)
                st.push({n->left, 1});
        }
        else if (num == 2)
        {
            inorder.push_back(n->data);
            ++st.top().second;
            if (n->right)
                st.push({n->right, 1});
        }
        else if (num == 3)
        {
            postorder.push_back(n->data);
            st.pop();
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
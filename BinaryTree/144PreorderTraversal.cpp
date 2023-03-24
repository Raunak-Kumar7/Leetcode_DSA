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
    void preorder(vector<int>& ans, TreeNode* root)
    {
        if(root == nullptr)
            return;
        ans.push_back(root->val);
        preorder(ans,root->left);
        preorder(ans,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans,root);
        return ans;
    }
};

//Instead of writing a separate Function , we can also declare the ans vector globally, and implement in the same function



//Iterative Approach:
    //we use STACK to replace Recursive Stack
    
    //ROOT  LEFT RIGHT
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* n = st.top();
            st.pop();
            ans.push_back(n->val);
            //Push Right first then left becuase LIFO so we want left to be on top to proccess it first
            if(n->right) st.push(n->right); 
            if(n->left) st.push(n->left);
        }
        return ans;
    }



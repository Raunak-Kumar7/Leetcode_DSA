//Apprach 1 O(n) S.C.
class BSTIterator {
public:
    TreeNode* root;
    vector<int> in;
    int i;
    void inorder(vector<int>& in, TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(in,root->left);
        in.push_back(root->val);
        inorder(in,root->right);
    }
    BSTIterator(TreeNode* r) {
        root = r;
        inorder(in,root);
        i=0;
    }
    int next() {
        return in[i++];
    }
    
    bool hasNext() {
        return i<in.size();
    }
};

//Approach 2 O(h) S.C.
//Using stack push till extreme left, when do next go right and push till extreme left
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root!=nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }
    int next() {
        TreeNode* ans = st.top();
        int a = ans->val;
        st.pop();
        if(ans->right){
            ans = ans->right;
            while(ans!=nullptr)
            {
                st.push(ans);
                ans = ans->left;
            }
        }
        return a;
    }
    
    bool hasNext() {
        if(st.size()>0)
            return true;
        return false;
    }
};
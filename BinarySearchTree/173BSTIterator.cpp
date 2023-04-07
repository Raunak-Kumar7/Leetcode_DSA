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
//Using stack push till extreme left, when not possible pop go right and push till extreme left
class BSTIterator {
public:
    //Approach 2: O(h) Space ------STACK------
    TreeNode* root;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* r) {
        root = r;
        while(root)
        {
            st.push(root);
            root = root->left;
        } 
    }
    
    int next() {
        int x = st.top()->val;
        TreeNode* temp = st.top();
        st.pop();
        temp = temp->right;
        while(temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        return x;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

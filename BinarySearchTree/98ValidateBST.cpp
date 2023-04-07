    //2 Conditions
    //1) Max in Left SubTree < N < Min in Right Subtree (Ranges Method)
    //2) Each node should satisfy
    bool valid(TreeNode* root, long min, long max)
    {
        if(root==nullptr)
            return true;
        return (root->val > min && root->val < max) && valid(root->left, min,root->val) && valid(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN,LONG_MAX); 
        //USE LONG_MIN AND LONG_MAX else cases where node values are equal to INT_MIN or INT_MAX fail
    }
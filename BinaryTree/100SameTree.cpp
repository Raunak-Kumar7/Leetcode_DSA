//S1: We can use any traversal
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr || q==nullptr)
            return false;
        //S2: Cond1: Equal value , Cond2: same left subtree and same right subtree
        return (p->val==q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right));
    }
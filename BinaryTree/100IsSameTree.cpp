bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        else if(p==nullptr || q==nullptr) return false;
        else{
            bool temp = false;
            if(p->val==q->val) temp = true;
            return (temp&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        }
    }
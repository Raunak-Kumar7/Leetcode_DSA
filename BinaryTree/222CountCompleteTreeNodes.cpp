// every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
    
    //Approach 1: Brute Force --> count number of nodes using any traversal(Pre,In,Post, Level)
    void inorder(TreeNode* root, int &cnt)
    {
        if(root==nullptr) return;
        inorder(root->left,cnt);
        cnt = cnt + 1; //change value before passing 
        inorder(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root,cnt);
        return cnt;
    }


// Approach 2: Using the property of Complete Trees (AND FULL TREES)
    // We dont need to calc no. of nodes(or height) at each node if we know that at that node subtree is FULL 2^h - 1
    // to check if its full left most height == right most height(as in complete tree last level is filled LtoR)
    int leftheight(TreeNode* root)
    {
        int h = 1;
        while(root)
        {
            root = root->left;
            h++;
        }
        return h;
    }
    int rightheight(TreeNode* root)
    {
        int h = 1;
        while(root)
        {
            root = root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lh = leftheight(root->left);
        int rh = rightheight(root->right);
        
        if(lh==rh)
            return pow(2,lh) - 1;
        
        //if not equal go deeper and add 1(i.e.) current node to the separe sums of LS and RS
        int l =  countNodes(root->left);
        int r = countNodes(root->right);
        
        return 1+l+r;
    }
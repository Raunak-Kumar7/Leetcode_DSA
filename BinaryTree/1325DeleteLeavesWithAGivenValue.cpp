//Postorder traversal (Recursive)
    // (it has to be postorder only because when both children are processed we can make decision for parent if its a leaf node or not)
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr) return nullptr;
        //When we are making changes to the children
        //To update the parent we reassign as root->left = call()
        //root->right = call()
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        if(root->left == nullptr && root->right==nullptr && root->val == target) return nullptr;
        return root;
    }
TreeNode* arrayToBST(vector<int>& arr,int f, int l)
    {
        if(f>l) //Base Case
            return nullptr;
        int mid = (f+l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = arrayToBST(arr,f,mid-1);
        root->right = arrayToBST(arr,mid+1,l);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int f = 0;
        int l = nums.size()-1;
        return arraytoBST(nums,f,l);
    }
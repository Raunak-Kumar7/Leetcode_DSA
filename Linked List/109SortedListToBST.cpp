//Brute Force Method 1- convert to array --> array to bst(mid as root)
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> a;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        return arrayToBST(a,0,n-1);
    }



//METHOD 2

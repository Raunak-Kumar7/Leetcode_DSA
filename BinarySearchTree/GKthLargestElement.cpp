////We can use Morris Traversal to omit Stack Space of O(n)

//Approach 1: Brute Force --> Store inorder in vec
    public:
    void inorder(Node* root, vector<int> &in)
    {
        if(root==nullptr) return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        vector<int> in;
        inorder(root,in);
        return in[in.size() - k];
    
    }

///
//Approach 2: Without storing the Inorder
    //Approach 2a): S1: Count nodes, S2: return n-kth node in inorder traversal
    public:
    int count(Node* root) //Function to count number of nodes
    {
        if(root==nullptr) return 0;
        int l = count(root->left);
        int r = count(root->right); 
        return 1+l+r;
    }
    void inorder(Node* root, int &k, int &ans)
    {
        if(root==nullptr) return;
        inorder(root->left,k,ans);
        k = k-1; // decrement before using root bcz 1 starts from left most root
        if(k==0)
        {
            ans = root->data;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int ans = -1;
        int n = count(root);
        //cout<<n;
        k = n-k+1;
        //cout<<k;
        inorder(root,k,ans); //don't pass n-k bcz its by refrence change before passing
        return ans;
    }

    
    //Approach 2: Without storing the Inorder
    //Approach 2b): Instead of counting number of nodes we can do Reverse Inorder Traversal
    void inorder(Node* root, int& k, int& ans)
    {
        if(root==nullptr)
            return;
        inorder(root->right,k,ans);
        k = k-1;
        if(k==0)
        {
            ans = root->data;
            return;
        }
        inorder(root->left,k,ans);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
class Solution {
public:
    bool isLeaf(Node* root)
    {
        if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
    }
    void addLeftBoundary(Node* root, vector<int>& res)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))
                res.push_back(curr->data);
            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addLeaves(Node* root, vector<int>& res) //recursive function
    {
        if(isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if(root->left)
            addLeaves(root->left,res);
        if(root->right)
            addLeaves(root->right,res);
    }
    void addRightBoundary(Node* root, vector<int>& res)
    {
        Node* curr = root->right;
        vector<int> temp;  //first traverse root right left because we are going from bottom to top on right side
        while(curr)
        {
            if(!isLeaf(curr))
                temp.push_back(curr->data);
            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for(int i=temp.size()-1;i>=0;--i)
        {
            res.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
        if(!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root,res);  //all 3 will not include root bcz written separately
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};
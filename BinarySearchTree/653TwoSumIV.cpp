    //Method 1: Brute Force
    //Store Inorder(Sorted) --> Problem converted to 2 Sum 
    void inorder(TreeNode* root,vector<int>& in)
    {
        if(root==nullptr) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        int i=0,j=in.size()-1;
        while(i<j)
        {
            if(in[i]+in[j]==k) 
                return true;
            else if(in[i]+in[j]>k)
                j--;
            else
                i++;
        }
        return false; //not found
    }


///ALSO CHECK STRIVER IMPLEMENTATION OF CLASS FOR BSTITERATOR FOR THIS QUES

    //Approach 2: BST Iterator (STACK) (Inorder traversal + reverse Inorder traversal)


    class BSTIterator{
  public:
    stack<TreeNode*> in;
    stack<TreeNode*> revin;
    BSTIterator(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp)
        {
            in.push(temp);
            temp = temp->left;
        }
        temp = root;
        while(temp)
        {
            revin.push(temp);
            temp = temp->right;
        }
    }
    TreeNode* left()
    {
        return in.top();
    }
    TreeNode* right()
    {
        return revin.top();
    }
    
    void next()
    {
        //int x = in.top()->val;
        TreeNode* temp = in.top();
        in.pop();
        temp = temp->right;
        while(temp)
        {
            in.push(temp);
            temp = temp->left;
        }
        //return x;
    }
    void before()
    {
        //int x = revin.top()->val;
        TreeNode* temp = revin.top();
        revin.pop();
        temp = temp->left;
        while(temp)
        {
            revin.push(temp);
            temp = temp->right;
        }
        //return x;
    }
};
class Solution {
public:
    //Approach 2: BST Iterator (STACK) (Inorder traversal + reverse Inorder traversal)
    bool findTarget(TreeNode* root, int k) {
        BSTIterator *obj = new BSTIterator(root);
        while(obj->left()!=obj->right())
        {
            if(obj->left()->val + obj->right()->val == k)
                return true;
            else if(obj->left()->val + obj->right()->val < k)
            {
                obj->next();
            }
            else
            {
                obj->before();
            }
        }
        return false;
    }
};
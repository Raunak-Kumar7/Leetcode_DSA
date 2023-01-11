/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Morris Order Traversal
    //Step1 -- Same as preorder only swap left and right everywhere in preorder code
    //Sttep2 -- At last reverse the Vector
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> postorder;
        TreeNode* cur = root;
        while(cur!=NULL)
        {
            if(cur->right==NULL)
            {
                postorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                TreeNode* prev = cur->right;
                while(prev->left && prev->left!=cur)
                {
                    prev = prev->left;
                }
                if(prev->left==NULL)
                {
                    prev->left = cur;
                    postorder.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    prev->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};
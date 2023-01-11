/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node == NULL)
            return;
        else
        {
            //Can be written in any order preorder,postorder or inorder
            Node* temp;
            temp = node->left;
            node->left = node->right;
            node->right = temp;
            mirror(node->left);
            mirror(node->right);
        }
        
    }
};
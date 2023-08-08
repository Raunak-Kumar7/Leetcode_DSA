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

class Solution
{
public:
    // Recursion
    // Swap left and right --> preorder Traversal
    void mirror(Node *node)
    {
        if (node == NULL)
            return;
        else
        {
            // Can be written in any order preorder,postorder or inorder
            Node *temp = node->left;
            ;
            node->left = node->right;
            node->right = temp;

            mirror(node->left);
            mirror(node->right);
        }
    }
};
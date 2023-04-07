
// Ceil = Smallest element greater or equal to 
int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root!=nullptr)
    {
        if(root->data == input)
            return root->data;
        else if(root->data > input)
        {
            ceil = root->data;  //Store potential ceil
            root = root->left;
        }
        else
            root = root->right;
    }
    return ceil;
}
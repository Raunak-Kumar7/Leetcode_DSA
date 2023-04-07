// Floor - Greatest element smaller or equal to the key
int floor(Node* root, int x) {
    int floor = -1;
    while(root!=nullptr)
    {
        if(root->data == x)
            return root->data;
        else if(root->data < x)
        {
            floor = root->data;  //Store Potential Floor
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}
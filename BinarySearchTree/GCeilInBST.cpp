int findCeil(Node* root, int key) {
    int ceil = INT_MAX; 
    while (root) {
 
        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
int floor(Node* root, int key) {
    // Code here
    int floor = -1; 
    while (root) {
 
        if (root->data == key) {
            floor = root->data;
            return floor;
        }
 
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}

// https://www.youtube.com/watch?v=WVFk9DwRgpY

// Inorder Traversal
void func(Node *root, int &f, Node *&head, Node *&prev)
{
    if (root == nullptr)
        return;

    func(root->left, f, head, prev);

    if (f == 0)
    {
        head = root;
        prev = root;
        f = 1;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    func(root->right, f, head, prev);
}
Node *bToDLL(Node *root)
{
    Node *head = nullptr;
    Node *prev = nullptr;
    int f = 0;
    func(root, f, head, prev);
    return head;
}
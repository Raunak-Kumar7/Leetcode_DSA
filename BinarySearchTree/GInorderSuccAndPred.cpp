Node *succ(Node *root, int key)
{
    Node *curr = nullptr;
    while (root)
    {
        if (root->key <= key)
            root = root->right;
        else if (root->key > key)
        {
            curr = root;
            root = root->left;
        }
    }
    return curr;
}
Node *pred(Node *root, int key)
{
    Node *curr = nullptr;
    while (root)
    {
        if (root->key < key)
        {
            curr = root;
            root = root->right;
        }
        else if (root->key >= key)
        {
            root = root->left;
        }
    }
    return curr;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = pred(root, key);
    suc = succ(root, key);
}

//---------------------------

// Dont use the second approach its too lengthy

//  ---------------------

/// Approach 2:

// This code gives result only if the node n exists in the tree

Node *search(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == data)
    {
        return root;
    }
    else if (root->key < data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
Node *minValue(Node *root)
{
    Node *current = root;
    while (current && current->left)
    {
        current = current->left;
    }
    return current;
}
Node *findsucc(Node *root, Node *n)
{
    if (n->right != NULL)
    {
        return minValue(n->right);
    }
    Node *succ = NULL;
    while (root != NULL)
    {
        if (n->key < root->key)
        {
            succ = root;
            root = root->left;
        }
        else if (n->key > root->key)
        {
            root = root->right;
        }
        else
            break;
    }
    return succ;
}
Node *maxValue(Node *root)
{
    Node *current = root;
    while (current && current->right)
    {
        current = current->right;
    }
    return current;
}
Node *findpred(Node *root, Node *n)
{
    if (n->left != NULL)
    {
        return maxValue(n->left);
    }
    Node *pred = NULL;
    while (root != NULL)
    {
        if (n->key > root->key)
        {
            pred = root;
            root = root->right;
        }
        else if (n->key < root->key)
        {
            root = root->left;
        }
        else
            break;
    }
    return pred;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    Node *n = search(root, key);
    // cout<<n->key;
    suc = NULL;
    suc = findsucc(root, root);
    pre = NULL;
    pre = findpred(root, root);
    // Your code goes here
}
// Exactly 2 nodes are swapped

// Method 1: Brute Force: Store the Inorder Traversal and sort it and again do the inorder traversal and overwrite where the value is not same
void inorder(vector<int> &in, TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(in, root->left);
    in.push_back(root->val);
    inorder(in, root->right);
}
void update(int &idx, vector<int> &in, TreeNode *root)
{
    if (root == nullptr)
        return;
    update(idx, in, root->left);
    if (in[idx] != root->val)
        root->val = in[idx];
    idx = idx + 1; // while passing by refernce dont change value inside function passing
    update(idx, in, root->right);
}
void recoverTree(TreeNode *root)
{
    vector<int> in;
    inorder(in, root);
    sort(in.begin(), in.end());
    for (auto i : in)
        cout << i << " ";
    int idx = 0;
    update(idx, in, root); // can not directly pass 0 as it is by refernce, so we need to create a memory(i.e.) variable bcz we are sending a memory location
}

// Optimal Appraoch : O(N) O(1)
// To compare nodes we use 2 pointers 1. root and 2.prev
//  to store voilations we use 3 pointers 1. first 2. mid 3. second
//  and we simply perform inorder traversal comparing prev and root;

void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&mid, TreeNode *&second)
{
    if (root == nullptr)
        return;

    inorder(root->left, prev, first, mid, second);

    if (first == nullptr && prev != nullptr && root->val < prev->val)
    {
        first = prev;
        mid = root;
    }
    else if (first != nullptr && prev != nullptr && root->val < prev->val)
    {
        second = root;
    }

    prev = root; // update prev OR we can use increment prev

    inorder(root->right, prev, first, mid, second);
}
void recoverTree(TreeNode *root)
{
    TreeNode *prev = new TreeNode(INT_MIN);
    TreeNode *first = nullptr;
    TreeNode *mid = nullptr;
    TreeNode *second = nullptr;

    inorder(root, prev, first, mid, second);

    if (second == nullptr) // adjacent violation
    {
        swap(first->val, mid->val);
    }
    else
    {
        swap(first->val, second->val);
    }
}
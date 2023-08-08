// S0: Add root separatly (if not leaf)
// S1: Print Left Boundary (start from curr = root->left) ITERATIVE Except Leavess and root(KEEP GOING LEFT1] Check if not leaf add 2] go left till possible 3] else go right)
// S2: Print Leaves (do Inorder Traversal) and keep adding if its a leaf (ONLY LEAVES IS RECURSIVE)
// S3: Print Right Boundary (start from curr = root->right) ITERATIVE Except Leaves and root Exactly same as left (KEEP GOING RIGHTAt last just reverse it)

// Also Implement isLeaf Function to check if its a leaf node or not

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        return (root->left == NULL && root->right == NULL);
    }
    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right; // Go right only when left is not possible
        }
    }
    void addLeaves(Node *root, vector<int> &res) // recursive function
    {
        if (root == nullptr)
            return;
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp; // first traverse root right left because we are going from bottom to top on right side
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root, res); // all 3 will not include root bcz written separately
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};
// Postorder Traversal
// need to maintain 3 values for each node so create a diff class

class NodeValue
{
public:
    int maxValue, minValue, maxSize;
    NodeValue(int mx, int mn, int sz)
    {
        maxValue = mx;
        minValue = mn;
        maxSize = sz;
    }
};

class Solution
{
public:
    NodeValue largestBSTHelper(Node *root)
    {
        if (root == nullptr)
        {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        auto left = largestBSTHelper(root->left);   // left
        auto right = largestBSTHelper(root->right); // right

        // root

        if (root->data > left.maxValue && root->data < right.minValue)
        {
            return NodeValue(max(right.maxValue, root->data), min(root->data, left.minValue), 1 + left.maxSize + right.maxSize);
        }
        else
        {
            return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
        }
    }
    int largestBst(Node *root)
    {
        return largestBSTHelper(root).maxSize;
    }
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second; // Find the subtractor outside the inner while loop itself //to make starting index always start from 0
            int first, last;
            //
            for (int i = 0; i < size; i++)
            {
                int cur_id = q.front().second - mmin; // Adjust root's index, no adjustments further
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;
                if (node->left != nullptr)
                    q.push({node->left, (long long)2 * cur_id + 1});
                if (node->right != nullptr)
                    q.push({node->right, (long long)2 * cur_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

////Same code just self written

// Level Order Traversal + Indexing of Nodes (2i+1,2i+2) with adjustment (each level starts from 0 index)
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q; // {node,index}
    q.push({root, 0});
    int width = 1;
    while (!q.empty())
    {
        int countNodes = q.size();
        int firstindex = q.front().second; // Find the subtractor outside the inner while loop itself
        while (countNodes > 0)
        {
            TreeNode *n = q.front().first;
            int i = q.front().second - firstindex; // Adjust root's index, no adjustments further
            q.pop();

            if (n->left)
                q.push({n->left, (long long)2 * i + 1});
            if (n->right)
                q.push({n->right, (long long)2 * i + 2});
            countNodes--;
            if (countNodes == 0) // last node in hand
            {
                width = max(width, i - 0 + 1); // index of each level starts from 0
            }
        }
    }
    return width;
}

// Again Self written same code
// Level Order Traversal + Indexing of each level
// we need to capture lowest and highest index of each level and take max of its diff
// also make sure to always substract the lower index while calling for children else it may overflow even for lon long
// still use long long while passing
int widthOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    queue<pair<TreeNode *, int>> q; //{node,index}
    q.push({root, 0});
    while (!q.empty())
    {
        int countNodes = q.size();
        int lowerIndex = INT_MAX;
        while (countNodes > 0)
        {
            TreeNode *n = q.front().first;
            int index = q.front().second;
            q.pop();
            if (lowerIndex == INT_MAX)
                lowerIndex = index; // will capture the first index of the level
            maxi = max(maxi, index - lowerIndex + 1);
            if (n->left)
                q.push({n->left, 2ll * index - lowerIndex});
            if (n->right)
                q.push({n->right, 2ll * index + 1 - lowerIndex});
            countNodes--;
        }
    }
    return maxi;
}
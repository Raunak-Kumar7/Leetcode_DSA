/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        while(!q.empty())
        {
            int nodeCount =q.size();
            vector<int> temp;
            while(nodeCount>0)
            {
                Node* n = q.front();
                q.pop();
                temp.push_back(temp->val);
                for(int i=0;i<n->children.size();i++)
                {
                    q.push(n->children[i]);
                }
                nodeCount--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
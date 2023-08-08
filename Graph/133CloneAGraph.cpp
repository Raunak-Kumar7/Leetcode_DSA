// https://www.youtube.com/watch?v=f2EfGComRKM
// DFS
// Graph is  connected undirected graph.
void dfs(Node *curr, Node *node, vector<Node *> &visited) // curr original node, node--> clone node
{
    // root
    visited[node->val] = node;

    // call all its children
    for (auto it : curr->neighbors)
    {
        if (visited[it->val] == nullptr) // not visited/created
        {
            Node *newNode = new Node(it->val);
            (node->neighbors).push_back(newNode);
            dfs(it, newNode, visited);
        }
        else
        {
            (node->neighbors).push_back(visited[it->val]);
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (node == nullptr)
        return node;

    vector<Node *> visited(101, nullptr); // we can also make it using a map of {old,new}
    Node *copy = new Node(node->val);
    visited[node->val] = copy;

    for (auto it : node->neighbors)
    {
        if (visited[it->val] == nullptr) // not visited/created
        {
            Node *newNode = new Node(it->val);
            (copy->neighbors).push_back(newNode);
            dfs(it, newNode, visited);
        }
        else
        {
            (copy->neighbors).push_back(visited[it->val]);
        }
    }
    return copy;
}
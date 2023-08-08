// If a cycle exists in the graph,
// All the nodes in the cycle will always keep rotating and never reach any terminal node
// similarly all nodes which are directly/indirectly connected(direct towards) a cycle will also never reach a terminal node

// Using DFS ( Cycle detecting in Directed Graph)
// If DFS CALL for a node is Completed(without any true returning) it is safe node

bool dfs(int root, vector<int> &visited, vector<int> &pathVisited, vector<vector<int>> &graph, vector<int> &ans)
{
    // root
    visited[root] = 1;
    pathVisited[root] = 1;

    // children
    for (auto it : graph[root])
    {
        if (!visited[it])
        {
            if (dfs(it, visited, pathVisited, graph, ans) == true)
                return true;
        }
        // node already visited and is on the SAME path --> in cycle
        else if (pathVisited[it])
        {
            return true;
        }
    }
    pathVisited[root] = 0; // unmark path visited
    ans.push_back(root);   // add to ans while returning as we return false for this
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    vector<int> ans;
    // check for all components
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, pathVisited, graph, ans); // even if cycle exists we need to find all safe nodes --> explore full graph
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// -----------------

// BFS (easy approach)
// S1: reverse the edges
// S2: Apply topo sort
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> adj(n); // reverse edges
    for (int i = 0; i < n; i++)
    {
        for (auto j : graph[i])
        {
            adj[j].push_back(i);
        }
    }
    // we can also omit creating an graph with reversed edges just by adding manipulating the indegree vector

    // apply topo sort --> vertices reachble from safe nodes are all safe nodes
    vector<int> indegree(n, 0);
    for (auto it : adj)
    {
        for (auto j : it)
        {
            indegree[j]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            int n = q.front();
            q.pop();

            ans.push_back(n);

            for (auto it : adj[n])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
            countNodes--;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
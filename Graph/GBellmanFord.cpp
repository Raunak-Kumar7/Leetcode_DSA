// Single src to all other nodes
// helps to detect -ve cycles (unlike Dijkstra)

// very simple O(N^2) loop iteration
// iterate over all edges n-1 times
// to check if -ve cycle exist --> iterate 1 more time and if any change --> negative cycle
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            dist[it[1]] = min(dist[it[1]], dist[it[0]] + it[2]);
        }
    }
    // checking -ve cycle
    for (auto it : edges)
    {
        if (dist[it[0]] + it[2] < dist[it[1]])
            return {-1};
    }
    return dist;
}
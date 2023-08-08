
// Dijkstra Algorithm + parent vector(along with distance vector)

// pq appraoch(simple bfs, instead of q use pq to get minimum first)
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]}); // undirected edges
    }
    int src = 1;
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    vector<int> dist(n + 1, INT_MAX); // 1 based indexing
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); //{dist,node}

    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            for (auto it : adj[p.second])
            {
                int mind = min(dist[it.first], p.first + it.second);
                if (mind < dist[it.first])
                {
                    pq.push({mind, it.first});
                    dist[it.first] = mind;
                    parent[it.first] = p.second; // only change from dijkstra code
                }
            }
            countNodes--;
        }
    }
    if (dist[n] == INT_MAX)
        return {-1};

    vector<int> ans;
    int dest = n;
    ans.push_back(dest);
    while (true)
    {
        ans.push_back(parent[dest]);
        if (parent[dest] == src)
            break;
        dest = parent[dest];
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
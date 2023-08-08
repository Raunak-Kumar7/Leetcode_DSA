// Shortest Path Undirected graph with all weights = 1
// find shortest dist from src to ALL nodes --> return dist vector
//  --> BFS  queue -> {node,dist}
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> dist(N, INT_MAX);
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]); // bidirectional edges
    }
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<int, int> p = q.front();
            q.pop();

            for (auto it : adj[p.first])
            {
                if (p.second + 1 < dist[it])
                {
                    dist[it] = p.second + 1;
                    q.push({it, p.second + 1});
                }
            }
            countNodes--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
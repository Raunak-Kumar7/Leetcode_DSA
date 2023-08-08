// Dijkstra Algorithm(using pq)
// find dist from src to all nodes pick the max
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1); // 1 based indexing
    for (auto it : times)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n + 1, INT_MAX); // 1 based indexing
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            for (auto it : adj[p.second])
            {
                if (dist[it.first] > p.first + it.second)
                {
                    pq.push({p.first + it.second, it.first});
                    dist[it.first] = p.first + it.second;
                }
            }
            countNodes--;
        }
    }

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        maxi = max(maxi, dist[i]);
    }
    return maxi;
}
// Not exactly Dijkstra Algorithm
// Queue is more efficient for this question
// here we {stops, node,dist}
// only change is we dont continue if the stops are >=k
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.push({0, {src, 0}}); //{stops,{src,dist}}

    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int stops = p.first;
            int node = p.second.first;
            int d = p.second.second;

            // only change
            if (stops > k)
                break;
            for (auto it : adj[node])
            {
                if (dist[it.first] > it.second + d)
                {
                    dist[it.first] = it.second + d;
                    q.push({stops + 1, {it.first, it.second + d}});
                }
            }
            countNodes--;
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
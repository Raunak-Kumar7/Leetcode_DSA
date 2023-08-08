// Function to find the shortest distance of all the vertices
// from the source vertex S.

// Dijkstra Algorithm (shortest dist form src to every other node)
// works for both directed and undirected(take bidirectional edges) graphs
// can not work with negative weights

// queue<< pq(min heap)<< set

// pq appraoch(simple bfs, instead of q use pq to get minimum first)
vector<int> dijkstra(int n, vector<vector<int>> adj[], int S)
{
    vector<int> dist(n, INT_MAX);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S}); //{dist,node}

    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            for (auto it : adj[p.second])
            {
                int mind = min(dist[it[0]], p.first + it[1]);
                if (mind < dist[it[0]])
                {
                    pq.push({mind, it[0]});
                    dist[it[0]] = mind;
                }
            }
            countNodes--;
        }
    }

    return dist;
}
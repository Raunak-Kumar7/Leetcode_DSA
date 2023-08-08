int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> visited(V, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    //{wt,{node,parent}}
    int sum = 0;

    pq.push({0, {0, -1}});
    // visited[0] = 1;
    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second.first;
            int parent = p.second.second;
            if (visited[node])
                break;
            visited[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                if (!visited[it[0]])
                {

                    pq.push({it[1], {it[0], node}});
                }
            }
            countNodes--;
        }
    }
    return sum;
}
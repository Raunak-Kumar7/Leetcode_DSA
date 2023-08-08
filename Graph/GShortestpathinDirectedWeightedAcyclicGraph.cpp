// Shortest path from Src to ALL the nodes, graph is directed and with weights

// S1. Do Topo Sort ( BFS or DFS(DAG so we dont need pathVisited))

// S2. relax the edges --> traverse the topo sort and keep taking minimum distances

// in this question --> INT_MAX doesn't work --> use 1e9
vector<int> topoSort(vector<vector<pair<int, int>>> &adj, int N)
{
    vector<int> topo;
    vector<int> indegree(N);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it.first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
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

            topo.push_back(n);
            for (auto it : adj[n])
            {
                indegree[it.first]--;
                if (indegree[it.first] == 0)
                {
                    q.push(it.first);
                }
            }
            countNodes--;
        }
    }
    return topo;
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]}); // directed graph
    }
    vector<int> topo = topoSort(adj, N);
    vector<int> dist(N, 1e9);
    dist[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[topo[i]])
        {
            dist[it.first] = min(dist[it.first], dist[topo[i]] + it.second);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
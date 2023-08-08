/// OR  -------Number of connected components in a graph------

// Adjacency Matrix Representation

// Number of Connected Components
// Just need to keep a counter in BFS/DFS
// Using BFS:
int findCircleNum(vector<vector<int>> &isConnected)
{
    // graph is in the form of adjacency matrix
    int v = isConnected.size();
    vector<int> visited(v, 0); // 1 based indexing (adjusted by -1)
    int cnt = 0;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            cnt++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int countNodes = q.size();
                while (countNodes > 0)
                {
                    int n = q.front();
                    q.pop();
                    for (int i = 0; i < v; i++)
                    {
                        if (isConnected[n][i] == 1)
                        {
                            if (!visited[i])
                            {
                                q.push(i);
                                visited[i] = 1;
                            }
                        }
                    }
                    countNodes--;
                }
            }
        }
    }
    return cnt;
}

// Using DFS
void dfs(vector<vector<int>> &isConnected, int v, vector<int> &visited, int root)
{
    // root
    visited[root] = 1;

    // call for children
    for (int i = 0; i < v; i++)
    {
        if (isConnected[root][i] == 1 && !visited[i])
        {
            dfs(isConnected, v, visited, i);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int v = isConnected.size();
    int cnt = 0;
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(isConnected, v, visited, i);
        }
    }
    return cnt;
}

//-----------------

//-----------------

// Using DSU

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<pair<int, int>> edges;
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (isConnected[i][j] == 1)
                    edges.push_back({i, j});
            }
        }
        // create DSU data structure as per the edges
        DisjointSet DSU(V);
        for (auto it : edges)
        {
            if (DSU.findUPar(it.first) != DSU.findUPar(it.second))
            {
                DSU.unionByRank(it.first, it.second);
            }
        }
        // DSU Created
        // now we can find number of components by 2 ways
        // 1. = no. of unique ultimate parents
        // 2. = no. of nodes in DSU where parent(u) = u

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (DSU.findUPar(i) == i)
                cnt++;
        }
        return cnt;
    }
// Using BFS
// Minimum Number of edges for a graph to be connected is n-1
// if  n-1 edges are there it is possible ( ans = number of components-1.  to connect a component require 1 edge)
int makeConnected(int n, vector<vector<int>> &connections)
{
    int edges = connections.size();
    if (n - 1 > edges)
        return -1;

    vector<int> visited(n, 0);
    // make a graph
    vector<vector<int>> graph(n);
    for (auto i : connections)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int countNodes = q.size();
                while (countNodes > 0)
                {
                    int node = q.front();
                    q.pop();
                    for (auto it : graph[node])
                    {
                        if (!visited[it])
                        {
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                    countNodes--;
                }
            }
        }
    }
    return components - 1;
}

//-----------

//----------

// Using DSU
#include <bits/stdc++.h>
using namespace std;
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
// count number of components
// count extra edges

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int extra = 0;
        DisjointSet DSU(n);
        for (auto it : connections)
        {
            if (DSU.findUPar(it[0]) != DSU.findUPar(it[1]))
            {
                DSU.unionByRank(it[0], it[1]);
            }
            else
            {
                extra++;
            }
        }
        int comp = 0;
        for (int i = 0; i < n; i++)
        {
            if (DSU.findUPar(i) == i)
                comp++;
        }
        if (extra < comp - 1)
            return -1;
        return comp - 1;
    }
};
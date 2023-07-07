class Solution
{
public:
    // GRAPH
    // weighted graph with edge weights as distance between centres
    // trying to start from every bomb as first and apply bfs to find max no of bombs for it
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<pair<int, double>>> graph(n); // stores {bombindex, distance bw centres}
        for (int i = 0; i < n; i++)
        {
            int x = bombs[i][0];
            int y = bombs[i][1];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double dist = pow((pow(x - bombs[j][0], 2) + pow(y - bombs[j][1], 2)), 0.5);
                    graph[i].push_back({j, dist});
                }
            }
        }
        int maxi = 0;
        // bfs using every bomb as first
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, 0);
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
                        if (it.second <= bombs[node][2] && !visited[it.first])
                        {
                            q.push(it.first);
                            visited[it.first] = 1;
                        }
                    }
                    countNodes--;
                }
            }
            maxi = max(maxi, accumulate(visited.begin(), visited.end(), 0));
        }
        return maxi;
    }
};
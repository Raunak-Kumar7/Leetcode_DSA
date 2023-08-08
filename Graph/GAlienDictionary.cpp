// Topological Sorting Ques
// There are 2 cases where an order doesn't exist
// 1. Smaller string is apperaing after a larger ex. {abc,abcd}
// 2. cycle Exists --> with dfs we need to use pathVisited concept

// using BFS
string topo(vector<int> adj[], int k)
{
    vector<int> indegree(k, 0);
    for (int i = 0; i < k; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    string ans = "";
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            int n = q.front();
            q.pop();
            ans.push_back('a' + n);
            for (auto it : adj[n])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
            countNodes--;
        }
    }
    if (ans.size() == k)
        return ans;
    return "0";
}
string findOrder(string dict[], int N, int K)
{
    // Creating Graph
    // Nodes = all unique characters = K, Edges = based on conditions = N
    if (N == 1 || K == 1)
        return "1";
    vector<int> adj[K]; // graph with K vertices
    for (int i = 1; i < N; i++)
    {
        string s1 = dict[i - 1];
        string s2 = dict[i];
        int len = min(s1.size(), s2.size());
        int idx = 0;
        bool flag = false;
        while (idx < len)
        {
            if (s1[idx] != s2[idx])
            {
                // means s1[i] is smaller than s2[i]
                flag = true;
                adj[s1[idx] - 'a'].push_back(s2[idx] - 'a');
                break;
            }
            idx++;
        }
        if (!flag && s1.size() > s2.size()) // no mismatch found
        {
            return "0"; // case 1 invalidity
        }
    }
    // graph created --> check if topo sort exists
    return topo(adj, K);
}
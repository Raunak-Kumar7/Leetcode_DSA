// same as dijkstra algortihtm
// we need to keeep an additional array called DP which stores number of ways
#define MOD 1000000007
#define ll long long
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<ll> dist(n, LONG_MAX);
    vector<ll> dp(n, 0);
    dist[0] = 0;
    dp[0] = 1;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 0});
    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<ll, ll> p = pq.top();
            pq.pop();

            for (auto it : adj[p.second])
            {
                if (dist[it.first] > p.first + it.second)
                {
                    pq.push({p.first + it.second, it.first});
                    dist[it.first] = p.first + it.second;
                    dp[it.first] = dp[p.second] % MOD; // same as parent --> new shorted path found
                }
                else if (dist[it.first] == p.first + it.second) // more path found
                {
                    dp[it.first] = (dp[it.first] % MOD + dp[p.second] % MOD) % MOD; // new route found from root to reach child add all new ways
                }
            }
            countNodes--;
        }
    }
    return dp[n - 1];
}
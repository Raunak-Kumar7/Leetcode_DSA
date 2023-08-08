// we need to find the distances from a city to all other cities
// Floyd Warshall
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dis(n, vector<int>(n, 1e7));
    for (auto it : edges)
    {
        dis[it[0]][it[1]] = it[2];
        dis[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
    }
    // applying floyd Warshall
    for (int i = 0; i < n; i++) // picking each row and column
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k)
                {
                    dis[j][k] = min(dis[j][k], dis[i][k] + dis[j][i]);
                }
            }
        }
    }

    // traversing each city to find the number of cities within threshold
    int mini = INT_MAX;
    int city = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && dis[i][j] <= distanceThreshold)
            {
                cnt++;
            }
        }
        if (cnt <= mini)
        {
            mini = cnt;
            city = i;
        }
    }
    return city;
}
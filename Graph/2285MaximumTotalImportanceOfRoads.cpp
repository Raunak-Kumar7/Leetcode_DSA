// Question is based on calculating indegree of the graph
long long maximumImportance(int n, vector<vector<int>> &roads)
{
    vector<int> indegree(n);
    int m = roads.size();
    for (int i = 0; i < m; i++)
    {
        indegree[roads[i][0]]++;
        indegree[roads[i][1]]++;
    }
    sort(indegree.begin(), indegree.end());
    long long score = 0;
    int city = 1;
    for (int i = 0; i < n; i++)
    {
        score += 1ll * city * indegree[i];
        city++;
    }
    return score;
}
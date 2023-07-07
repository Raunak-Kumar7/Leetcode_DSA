// Line Sweep Prefix Sum --> if any value of prefix array > capacity --> not possible
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    int n = trips.size();
    vector<int> dist(1002); // 1 extra to handle R+1
    for (int i = 0; i < n; i++)
    {
        dist[trips[i][1]] += trips[i][0];
        dist[trips[i][2]] -= trips[i][0]; // actually we dont need to do +1 bcz R is not inclusive in this case, passengers leave and create space for others at same stop
    }
    if (dist[0] > capacity)
        return false;
    for (int i = 1; i < 1002; i++)
    {
        dist[i] = dist[i] + dist[i - 1];
        if (dist[i] > capacity)
            return false;
    }
    return true;
}
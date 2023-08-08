#define ll long long
bool isValid(vector<int> &dist, double hour, ll mid)
{
    // calc time with speed as mid;
    int n = dist.size();
    double time = 0;
    for (int i = 0; i < n - 1; i++)
    {
        time += ceil(1.0 * dist[i] / mid);
    }
    time += 1.0 * dist[n - 1] / mid; // last can be less than 1 hour so handling without ceil
    return time <= hour;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int n = dist.size();
    ll f = 1;
    ll l = INT_MAX; // taking INT_MAX and not the max element eg. this case[1,1,100000]  2.01
    ll ans = -1;
    while (f <= l)
    {
        ll mid = (f + l) / 2;
        if (isValid(dist, hour, mid))
        {
            ans = mid;
            l = mid - 1; // minimise
        }
        else
        {
            f = mid + 1;
        }
    }
    return ans;
}
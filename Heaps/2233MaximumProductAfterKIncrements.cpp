// Increase the smaller elements first(which act as a multiplier)
// 1X45 --> 2X45 = 90 , 1X46 = 46
#define ll long long
#define MOD 1000000007
int maximumProduct(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : nums)
        pq.push(it);
    while (k--)
    {
        int x = pq.top();
        x++;
        pq.pop();
        pq.push(x);
    }
    ll ans = 1;
    while (!pq.empty())
    {
        ans = (ans * pq.top()) % MOD;
        pq.pop();
    }
    return ans % MOD;
}
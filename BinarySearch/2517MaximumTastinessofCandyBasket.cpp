// as prices is sorted --> ATLEAST a diff of mid must be maintained bw 2 candies and we need to check that by doing so can we make a basket of size k
bool isValid(vector<int> &price, int k, int mid, int n)
{

    int basket = 1;
    int prev = price[0];
    for (int i = 1; i < n; i++)
    {
        if (price[i] - prev >= mid)
        {
            basket++;
            prev = price[i];
        }
    }
    return basket >= k;
}
int maximumTastiness(vector<int> &price, int k)
{
    int n = price.size();
    sort(price.begin(), price.end());
    int f = 0;
    int l = price[n - 1] - price[0];
    int ans = 0;
    while (f <= l)
    {
        int mid = (f + l) / 2;
        if (isValid(price, k, mid, n))
        {
            ans = mid;
            f = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    return ans;
}
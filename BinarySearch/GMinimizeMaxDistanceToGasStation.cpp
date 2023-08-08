// answers within 1e6 will be considered as correct
bool isValid(vector<int> &stations, int K, int n, double mid)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (stations[i] - stations[i - 1] <= mid)
            continue;

        else
        {
            double d = 1.0 * (stations[i] - stations[i - 1]);
            double cnt1 = d / mid;
            // if(cnt1==(int)cnt1)
            cnt += (int)cnt1; // - 1;
            // else
            //     cnt += (int)cnt1 + 1;
        }
    }
    return cnt <= K;
}
double findSmallestMaxDist(vector<int> &stations, int K)
{
    int n = stations.size();
    double f = 0;
    double l = stations[n - 1] - stations[0];
    //   for(int i=1;i<n;i++)
    //   {
    //       l = max(l, 1.0*(stations[i] - stations[i-1]));
    //   }
    // cout<<f<<".  "<<l;
    double ans = 0.0;
    while (l - f >= 1e-6)
    {
        double mid = (f + l) / 2;
        if (isValid(stations, K, n, mid))
        {
            ans = mid;
            l = mid; // - 0.01;//minimize;
        }
        else
        {
            f = mid; // + 0.01; //2 decimal places
        }
    }
    return ans;
}
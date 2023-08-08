// count till index
// sliding window
int longestSemiRepetitiveSubstring(string s)
{
    int n = s.size();
    vector<int> index(n, 0);
    index[0] = 0;
    int maxi = 1;
    int start = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            index[i] = index[i - 1] + 1;
        else
            index[i] = index[i - 1];

        if (index[i] - index[start] <= 1)
            maxi = max(maxi, i - start + 1);
        else
        {
            while (index[i] - index[start] > 1)
            {
                start++;
            }
            maxi = max(maxi, i - start);
        }
    }
    return maxi;
}
// it is equal to number of alternating bits from left
int minFlips(string target)
{
    int n = target.size();
    auto find = target.find("1");
    if (find == string::npos)
        return 0;
    int cnt = 1;
    int prev = 1;
    for (int i = find; i < n; i++)
    {
        if (prev == 1 && target[i] == '0')
        {
            cnt++;
            prev = 0;
        }
        else if (prev == 0 && target[i] == '1')
        {
            cnt++;
            prev = 1;
        }
    }
    return cnt;
}
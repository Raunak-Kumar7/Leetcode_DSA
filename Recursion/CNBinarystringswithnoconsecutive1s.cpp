void f(vector<string> &ans, string &temp, int idx, int N)
{
    if (idx == N) // base case
    {
        ans.push_back(temp);
        return;
    }

    if (idx == 0)
    {
        f(ans, temp, idx + 1, N); // 0 at 0th index
        temp[0] = '1';
        f(ans, temp, idx + 1, N);
        temp[0] = '0'; // reset
    }
    else
    {
        if (temp[idx - 1] == '1') // only possible is 0
        {
            f(ans, temp, idx + 1, N);
        }
        else // next can be 1 or 0
        {
            f(ans, temp, idx + 1, N); // 0
            temp[idx] = '1';
            f(ans, temp, idx + 1, N); // 1
            temp[idx] = '0';          // reset
        }
    }
}
vector<string> generateString(int N)
{
    vector<string> ans;
    string temp = string(N, '0');
    f(ans, temp, 0, N);
    return ans;
}
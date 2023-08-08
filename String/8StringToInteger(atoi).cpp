// #include<boost/algorithm/string.hpp>
// boost::trim_right(myStr);
int myAtoi(string s)
{
    int n = s.size();
    // ignore leading white spaces (can also use trim)
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            start = i;
            break;
        }
    }
    // if all whitespaces
    if (start == -1)
        return 0;
    // move forward until you encounter a + - or a digit
    int start2 = start;
    bool sign = false;
    bool pos = true;
    for (int i = start; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            start2 = i;
            break;
        }
        if (s[i] == '+')
        {
            sign = true;
            start2 = i + 1;
            break; // break is needed bcz eg.+-12
        }
        else if (s[i] == '-')
        {
            sign = true;
            pos = false;
            start2 = i + 1;
            break;
        }
        else //"words and 987" --> 0
        {
            return 0;
        }
    }
    // number starts from start2 and check till you get digits
    long long ans = 0;
    int i = start2;
    while (s[i] >= '0' && s[i] <= '9')
    {
        ans = ans * 10 + (s[i] - '0');
        if (ans >= INT_MAX && pos)
            return INT_MAX;
        if (ans > INT_MAX && !pos)
            return INT_MIN;
        i++;
    }
    if (pos)
        return ans;
    return -1 * ans;
}
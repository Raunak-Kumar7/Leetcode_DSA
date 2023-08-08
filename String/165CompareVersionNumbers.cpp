string removeLeadingZeros(string temp)
{
    int n = temp.size();
    int i = 0;
    while (temp[i] == '0')
    {
        i++;
    }
    return temp.substr(i, n - i);
}
bool checkNonZero(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '1' && s[i] <= '9')
            return true;
    }
    return false;
}
int compareVersion(string version1, string version2)
{
    version1 = version1 + '.';
    version2 = version2 + '.';
    int n1 = version1.size();
    int n2 = version2.size();
    int i = 0;
    int j = 0;
    while (n1 > 0 && n2 > 0)
    {
        auto p1 = version1.find(".");
        auto p2 = version2.find(".");
        string t1 = removeLeadingZeros(version1.substr(i, p1));
        string t2 = removeLeadingZeros(version2.substr(i, p2));
        if (t1 != "" && t2 != "" && stoi(t1) < stoi(t2)) //"1.2" "1.10" --> -1
            return -1;
        else if (t1 != "" && t2 != "" && stoi(t1) > stoi(t2))
            return 1;
        else if (t1 == "" && t2 != "")
            return -1;
        else if (t2 == "" && t1 != "")
            return 1;
        version1 = version1.substr(p1 + 1);
        version2 = version2.substr(p2 + 1);
        n1 = version1.size();
        n2 = version2.size();
    }
    if (n1 > 0)
    {
        if (checkNonZero(version1)) // "1.0", "1.0.0" --> 0
            return 1;
        return 0;
    }
    else if (n2 > 0)
    {
        if (checkNonZero(version2))
            return -1;
        return 0;
    }
    return 0;
}
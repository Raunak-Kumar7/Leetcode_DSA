// Recursive --> TLE

// generate all subsequences put in set to count
// pick not pick
void count(string s, int idx, int n, string &temp, unordered_set<string> &st)
{
    if (idx == n)
    {
        st.insert(temp);
        return;
    }

    // not pick
    count(s, idx + 1, n, temp, st);

    // pick
    temp.push_back(s[idx]);
    count(s, idx + 1, n, temp, st);
    temp.pop_back();
}
string betterString(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    unordered_set<string> st1;
    unordered_set<string> st2;
    string temp = "";
    count(str1, 0, n, temp, st1);
    temp = "";
    count(str2, 0, m, temp, st2);
    int a1 = st1.size();
    int a2 = st2.size();
    if (a1 == a2)
        return str1;
    return a1 > a2 ? str1 : str2;
}

// Optimised DP
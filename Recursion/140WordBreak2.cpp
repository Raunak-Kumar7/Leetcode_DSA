// Backtracking approach
//  https://www.youtube.com/watch?v=LmHWIsBQBU4
void f(vector<string> &ans, unordered_set<string> &st, int ind, string &s, int n, string &temp)
{
    if (ind == n)
    {
        ans.push_back(temp.substr(0, temp.size() - 1)); // remove space added at the end
        return;
    }
    string t = "";
    string copy = temp;
    int indc = ind;
    for (int i = ind; i < n; i++)
    {
        t += s[i];
        if (st.find(t) != st.end())
        {
            temp = temp + t + " ";
            ind = i + 1;
            f(ans, st, ind, s, n, temp);
            temp = copy;
            ind = indc;
        }
    }
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<string> ans;
    unordered_set<string> st;
    for (auto it : wordDict)
        st.insert(it);
    string temp = "";
    int n = s.size();
    f(ans, st, 0, s, n, temp);
    return ans;
}
// All Possible paths
// Backtracking

// no cell can be visited more than one time --> visited array
// paths in lexicographically increasing order. --> process in DLRU order
void f(vector<string> &ans, string &temp, vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(temp);
        return;
    }

    if (i + 1 < n && !visited[i + 1][j] && m[i + 1][j] == 1)
    {
        temp.push_back('D');
        visited[i + 1][j] = 1;
        f(ans, temp, m, visited, i + 1, j, n);
        visited[i + 1][j] = 0;
        temp.pop_back();
    }
    if (j - 1 >= 0 && !visited[i][j - 1] && m[i][j - 1] == 1)
    {
        temp.push_back('L');
        visited[i][j - 1] = 1;
        f(ans, temp, m, visited, i, j - 1, n);
        visited[i][j - 1] = 0;
        temp.pop_back();
    }
    if (j + 1 < n && !visited[i][j + 1] && m[i][j + 1] == 1)
    {
        temp.push_back('R');
        visited[i][j + 1] = 1;
        f(ans, temp, m, visited, i, j + 1, n);
        visited[i][j + 1] = 0;
        temp.pop_back();
    }
    if (i - 1 >= 0 && !visited[i - 1][j] && m[i - 1][j] == 1)
    {
        temp.push_back('U');
        visited[i - 1][j] = 1;
        f(ans, temp, m, visited, i - 1, j, n);
        visited[i - 1][j] = 0;
        temp.pop_back();
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return {"-1"};

    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    vector<string> ans;
    string temp = "";
    f(ans, temp, m, visited, 0, 0, n);
    return ans;
}
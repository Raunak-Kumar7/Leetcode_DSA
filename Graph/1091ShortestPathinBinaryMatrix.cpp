// TRAVERSING USING ZEROS
// keeping a count for each cell
//  BFS
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
        return -1;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> delrow = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    vector<int> delcol = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<int, int> node = q.front();
            q.pop();
            for (int i = 0; i < delrow.size(); i++)
            {
                int childR = node.first + delrow[i];
                int childC = node.second + delcol[i];

                if ((childR >= 0 && childR < m && childC >= 0 && childC < n) && !visited[childR][childC] && grid[childR][childC] == 0)
                {
                    q.push({childR, childC});
                    visited[childR][childC] = visited[node.first][node.second] + 1;
                }
                else if ((childR >= 0 && childR < m && childC >= 0 && childC < n) && grid[childR][childC] == 0) // already visited
                {
                    visited[childR][childC] = min(visited[childR][childC], visited[node.first][node.second] + 1);
                }
            }
            countNodes--;
        }
    }
    if (visited[m - 1][n - 1] == 0)
        return -1;
    return visited[m - 1][n - 1];
}
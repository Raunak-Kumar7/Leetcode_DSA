// Dijkstra Algorithm(using pq {diff,{i,j}})
// we need to go in all 4 directions
int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};
    vector<vector<int>> diff(m, vector<int>(n, 1e9));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}});
    diff[0][0] = 0;
    while (!pq.empty())
    {
        int countNodes = pq.size();
        while (countNodes > 0)
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if (x == m - 1 && y == n - 1) // it will be minimum if we reached
                return d;

            for (int i = 0; i < delrow.size(); i++)
            {
                int childR = x + delrow[i];
                int childC = y + delcol[i];

                if ((childR >= 0 && childR < m && childC >= 0 && childC < n) && diff[childR][childC] > max(d, abs(heights[x][y] - heights[childR][childC])))
                {
                    int potDiff = max(d, abs(heights[x][y] - heights[childR][childC]));
                    pq.push({potDiff, {childR, childC}});
                    diff[childR][childC] = potDiff;
                }
            }
            countNodes--;
        }
    }
    return diff[m - 1][n - 1];
}
// ----2 SOLUTIONS----

// Approach 1:
// Brute force: make a new array
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // S1: store the indices of 0s
    vector<pair<int, int>> vi;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                vi.push_back({i, j});
            }
        }
    }
    // first make all rows 0
    // then make all columns 0
    for (auto it : vi)
    {
        // rows
        for (int j = 0; j < n; j++)
            matrix[it.first][j] = 0;

        // columns
        for (int i = 0; i < m; i++)
            matrix[i][it.second] = 0;
    }
}

// Approach 2:

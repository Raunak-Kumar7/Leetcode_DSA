// User function template for C++

class Solution
{
public:
    // shortest path between every two vertices
    // Also helps to detect -ve cycles
    // if graph is undirected --> first convert it to directed graph
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1) // not reachable
                {
                    matrix[i][j] = 10000;
                }
            }
        }

        for (int i = 0; i < m; i++) // picking ith row and ith column
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    if (j != i && k != i)
                    {
                        matrix[j][k] = min(matrix[j][k], matrix[i][k] + matrix[j][i]);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 10000) // not reachable
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};
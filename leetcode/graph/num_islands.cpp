#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector < vector<char> >&grid, int i, int j, int &rows, int &cols) {
        grid[i][j] = '2';
        
        if (j + 1 < cols && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1, rows, cols);
        if(j - 1 >= 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1, rows, cols);
        if (i + 1 < rows && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j, rows, cols);
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++)    
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return count;
    }
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector< vector<char> > grid(rows, vector<char> (cols, 0));

    for (int i = 0; i < rows; i++)    
    {
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];
    }

    Solution sol;
    cout << sol.numIslands(grid) << '\n';

    return 0;
}
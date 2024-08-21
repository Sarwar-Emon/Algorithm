#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int> > &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Start from top-right corner
        int row = 0;
        int col = n - 1;

        // Move towards bottom-left corner
        while (row < m && col >= 0)
        {
            if (grid[row][col] < 0)
            {
                // All elements to the left are also negative
                count += (m - row);
                // Move to the previous column
                col--;
            }
            else
            {
                // Move to the next row
                row++;
            }
        }

        return count;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<vector<int> > grid1 = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    vector<vector<int> > grid2 = {{3, 2}, {1, 0}};

    // Example 1
    int result1 = sol.countNegatives(grid1); // Output: 8

    // Example 2
    int result2 = sol.countNegatives(grid2); // Output: 0

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        vector<int> targetIndices;

        // Step 2: Find target indices
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                targetIndices.push_back(i);
            }
        }

        return targetIndices;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 5, 2, 3}; // Sample array
    int target = 3;                     // Sample target element

    vector<int> result = sol.targetIndices(nums, target);

    // Output the result
    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

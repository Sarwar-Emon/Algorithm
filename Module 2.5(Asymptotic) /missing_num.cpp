#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        // Calculate the expected sum of numbers from 0 to n
        int expectedSum = (n * (n + 1)) / 2;
        // Calculate the actual sum of numbers in nums
        int actualSum = 0;
        for (int num : nums)
        {
            actualSum += num;
        }
        // The difference between the expected sum and actual sum will be the missing number
        return expectedSum - actualSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 0, 1}; // Example array
    cout << "Missing number: " << sol.missingNumber(nums) << endl;
    return 0;
}

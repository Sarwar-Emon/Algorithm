#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos = 0, neg = 0;

        for (int num : nums)
        {
            if (num > 0)
            {
                pos++;
            }
            else if (num < 0)
            {
                neg++;
            }
        }

        return max(pos, neg);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, -3, 4, -5};
    cout << "Maximum count: " << sol.maximumCount(nums) << endl;
    return 0;
}

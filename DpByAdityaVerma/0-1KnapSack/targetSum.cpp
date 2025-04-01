#include <iostream>
using namespace std;

// Memoised
class Solution
{
public:
    vector<vector<int>> dp;
    int offSet;

    int solve(vector<int> &nums, int i, int sum, int target)
    {
        if (i == nums.size())
            return sum == target;

        if (dp[i][sum + offSet] != -1)
            return dp[i][sum + offSet];
        int add = solve(nums, i + 1, sum + nums[i], target);
        int sub = solve(nums, i + 1, sum - nums[i], target);

        return dp[i][sum + offSet] = add + sub;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int &num : nums)
            sum += num;
        offSet = sum;
        dp = vector<vector<int>>(nums.size() + 1, vector<int>(2 * sum + 1, -1));
        return solve(nums, 0, 0, target);
    }
};

int main()
{
    return 0;
}
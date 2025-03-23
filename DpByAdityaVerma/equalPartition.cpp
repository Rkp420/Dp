#include <iostream>
using namespace std;
class Solution
{
public:
    bool subsetSum(vector<int> &nums, int sum)
    {
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, true));

        for (int i = 1; i <= sum; i++)
            dp[0][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }

    bool canPartition(vector<int> &nums)
    {
        long long sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        if (sum % 2 != 0)
            return false;

        return subsetSum(nums, sum / 2);
    }
};

int main()
{
    return 0;
}
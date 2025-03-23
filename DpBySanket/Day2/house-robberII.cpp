#include <iostream>
using namespace std;
// BruteForce Approach
class Solution
{
public:
    int maxRob(vector<int> &nums, int i, bool canRobLastHouse)
    {
        if (i >= nums.size())
            return 0;

        if (i == nums.size() - 1 && !canRobLastHouse)
            return 0;

        // Case 1 : if We rob Current House
        // Option 1: Skip this house
        int skipThis = maxRob(nums, i + 1, canRobLastHouse);

        // Option 2: Rob this house (only update `canRobLastHouse` for the first
        // house)
        int robThis = 0;
        if (i == 0)
            robThis = nums[i] + maxRob(nums, i + 2, false); // First house robbed → canRobLastHouse = false
        else
            robThis = nums[i] + maxRob(nums, i + 2, canRobLastHouse); // Other houses → keep flag unchanged

        return max(robThis, skipThis);
    }
    int rob(vector<int> &nums)
    {
        return maxRob(nums, 0, true);
    }
};

// Memoisation 

class Solution
{
public:
    int maxRob(vector<int> &nums, int i, bool canRobLastHouse, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
            return 0;

        if (i == nums.size() - 1 && !canRobLastHouse)
            return 0;

        if (dp[i][canRobLastHouse] != -1)
            return dp[i][canRobLastHouse];

        int skipThis = maxRob(nums, i + 1, canRobLastHouse, dp);

        int robThis = 0;
        if (i == 0)
            robThis = nums[i] + maxRob(nums, i + 2, false, dp); 
        else
            robThis = nums[i] + maxRob(nums, i + 2, canRobLastHouse, dp);

        return dp[i][canRobLastHouse] = max(robThis, skipThis);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxRob(nums, 0, true, dp);
    }
};

// Bottom - Up Approach 
class Solution
{
public:
    int maxRob(vector<int> &nums, int st, int end)
    {
        if (st > end)
            return 0;

        int n = end - st + 1;
        if (n == 1)
            return nums[st];

        // Top- down Approach
        vector<int> dp(n, 0);
        dp[0] = nums[st];
        dp[1] = max(nums[st], nums[st + 1]);

        for (int i = 2; i < n; i++)
        {

            // Pick
            int x = nums[st + i] + dp[i - 2];

            int y = dp[i - 1];

            dp[i] = max(x, y);
        }

        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int rob1 = maxRob(nums, 0, n - 2);
        int rob2 = maxRob(nums, 1, n - 1);
        return max(rob1, rob2);
    }
};

int main()
{
    return 0;
}
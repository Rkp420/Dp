#include <iostream>
using namespace std;

// Recursive Approach
class Solution
{
public:
    int maxRob(vector<int> &nums, int i , bool &flag)
    {
        if ((flag && i >= nums.size() - 1) || (!flag && i >= nums.size()))
            return 0;

        // If He robs at Current House
        int x = 0;
        if(i == 0){
            flag = true;
            x = nums[i] + maxRob(nums, i + 2 ,flag);
        }
        else
            x = x = nums[i] + maxRob(nums, i + 2, flag);

        // If he don't rob at Current House
        int y = maxRob(nums, i + 1 , flag);

        return max(x, y);
    }

    int rob(vector<int> &nums)
    {
        bool flag = false;
        return maxRob(nums, 0, flag);
    }
};

// Memoisation

class Solution
{
public:
    int maxRob(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // If He robs at Current House
        int x = nums[i] + maxRob(nums, i + 2, dp);

        // If he don't rob at Current House
        int y = maxRob(nums, i + 1, dp);

        return dp[i] = max(x, y);
    }

    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return maxRob(nums, 0, dp);
    }
};

// Top - down Approach
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // Top- down Approach
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {

            // Pick
            int x = nums[i - 1] + dp[i - 2];

            int y = dp[i - 1];

            dp[i] = max(x, y);
        }

        return dp[n];
    }
};

// Simple Recursion
int maxRob(vector<int> &nums, int i){
    if(i == nums.size() - 1) return nums[i];
    if(i == nums.size() - 2) return max(nums[i], nums[i+1]);

    return max(nums[i] + maxRob(nums, i + 2), 0 + maxRob(nums, i + 1));
}

int main()
{


    return 0;
}
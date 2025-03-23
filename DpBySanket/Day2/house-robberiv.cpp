#include <iostream>
using namespace std;

// Using Simple Recursion Based On Choices
class Solution
{
public:
    int n;
    int solve(vector<int> &nums, int i, int k, vector<vector<int>> &dp)
    {
        if (k == 0)
            return 0;
        if (i >= n)
            return INT_MAX;

        if(dp[i][k] != -1) return dp[i][k];

        int take = max(nums[i], solve(nums, i + 2, k - 1, dp));

        int not_take = solve(nums, i + 1, k, dp);

        return dp[i][k] = min(take, not_take);
    }

    int minCapability(vector<int> &nums, int k)
    {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        return solve(nums, 0, k, dp);
    }
};

// Memoisation
class Solution
{
public:
    int n;
    int solve(vector<int> &nums, int i, int k, vector<vector<int>> &dp)
    {
        if (k == 0)
            return 0;
        if (i >= n)
            return INT_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        int take = max(nums[i], solve(nums, i + 2, k - 1, dp));

        int not_take = solve(nums, i + 1, k, dp);

        return dp[i][k] = min(take, not_take);
    }

    int minCapability(vector<int> &nums, int k)
    {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(nums, 0, k, dp);
    }
};

// Binary Search
class Solution
{
public:
    bool isPossible(int capability, vector<int> &nums, int k)
    {
        int house = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= capability)
            {
                house++;
                i++;
            }
        }

        return house >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int result = r;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, nums, k))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
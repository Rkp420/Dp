
#include <iostream>
using namespace std;

// Simple Recursive Approach

class Solution
{
public:
    int solve(vector<int> &arr, int i, int sum, int target)
    {
        if (i == arr.size())
            return target == sum;

        int pick = solve(arr, i + 1, sum + arr[i], target);
        int notPick = solve(arr, i + 1, sum, target);

        return pick + notPick;
    }
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int totalSum = 0;
        for (int &num : arr)
            totalSum += num;

        if ((totalSum + d) % 2 != 0 || totalSum < d)
            return 0;

        int target = (totalSum + d) / 2;
        return solve(arr, 0, 0, target);
    }
};

// Memoisation

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr, int i, int sum, int target)
    {
        if (i == arr.size())
            return target == sum;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int pick = 0;
        if (arr[i] + sum <= target)
            pick = solve(arr, i + 1, sum + arr[i], target);
        int notPick = solve(arr, i + 1, sum, target);

        return dp[i][sum] = pick + notPick;
    }
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int totalSum = 0;
        for (int &num : arr)
            totalSum += num;

        if ((totalSum + d) % 2 != 0 || totalSum < d)
            return 0;

        int target = (totalSum + d) / 2;
        dp.resize(n + 1, vector<int>(target + 1, -1));
        return solve(arr, 0, 0, target);
    }
};

// Bottom - Up

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int totalSum = 0;
        for (int &num : arr)
            totalSum += num;

        if ((totalSum + d) % 2 != 0 || totalSum < d)
            return 0;

        int target = (totalSum + d) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int notPick = dp[i - 1][j];

                int pick = 0;
                if (j >= arr[i - 1])
                    pick = dp[i - 1][j - arr[i - 1]];

                dp[i][j] = pick + notPick;
            }
        }

        return dp[n][target];
    }
};

// Space Optimisation

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int totalSum = 0;
        for (int &num : arr)
            totalSum += num;

        if ((totalSum + d) % 2 != 0 || totalSum < d)
            return 0;

        int target = (totalSum + d) / 2;
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int &num : arr)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};

int main(){

    return 0;
}

#include <iostream>
using namespace std;

// Recursion + Memoisation

class Solution1
{
public:
    // Function to return max value that can be put in knapsack of capacity.

    int maxProfit(int capacity, vector<int> &val, vector<int> &wt,
                  int n, vector<vector<int>> &dp)
    {
        if (capacity == 0 || n == 0)
            return 0;

        // Check if We Already Solved.
        if (dp[n][capacity] != -1)
            return dp[n][capacity];

        if (wt[n - 1] <= capacity)
            return dp[n][capacity] = max(
                       val[n - 1] + maxProfit(capacity - wt[n - 1], val, wt, n - 1, dp),
                       maxProfit(capacity, val, wt, n - 1, dp));

        else
            return dp[n][capacity] = maxProfit(capacity, val, wt, n - 1, dp);
    }

    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = val.size();

        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        return maxProfit(capacity, val, wt, n, dp);
    }
};

// Iterative Top Down Approach

class Solution2
{
public:
    // Function to return max value that can be put in knapsack of capacity

    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = val.size();

        int dp[n + 1][capacity + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= capacity; j++)
        {
            dp[0][j] = 0;
        }

        // Now Finally
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                if (wt[i - 1] <= capacity)
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][capacity];
    }
};

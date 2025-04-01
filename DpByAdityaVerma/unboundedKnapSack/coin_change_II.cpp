#include <iostream>
using namespace std;

// Simple Recursion
class Solution
{
public:
    int solve(vector<int> &coins, int amount, int idx)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || idx == coins.size())
            return 0;

        return solve(coins, amount - coins[idx], idx) + solve(coins, amount, idx + 1);
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return solve(coins, amount, 0);
    }
};


// Top - down 
class Solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<int> &coins, int amount, int idx)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || idx == coins.size())
            return 0;

        if (dp[amount][idx] != -1)
            return dp[amount][idx];
        return dp[amount][idx] = solve(coins, amount - coins[idx], idx) + solve(coins, amount, idx + 1);
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        dp = vector<vector<int>>(amount + 1, vector<int>(n, -1));
        return solve(coins, amount, 0);
    }
};

// Bottom - Up

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: There is one way to make amount 0 (by taking nothing)
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int notTake = (i > 0) ? dp[i - 1][j] : 0;
                int take = (j >= coins[i]) ? dp[i][j - coins[i]] : 0;
                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

int main()
{
    return 0;
}
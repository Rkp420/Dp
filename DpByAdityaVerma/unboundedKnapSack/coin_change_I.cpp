#include <iostream>
using namespace std;

// Simple Recursion
class Solution
{
public:
    int solve(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int res = solve(coins, amount - coin);
            if (res != INT_MAX)
                minCoins = min(minCoins, 1 + res);
        }

        return minCoins;
    }
    int coinChange(vector<int> &coins, int amount)
    {

        int ans = solve(coins, amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};

// Top - down
class Solution
{
public:
    vector<int> dp;
    int solve(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int res = solve(coins, amount - coin);
            if (res != INT_MAX)
                minCoins = min(minCoins, 1 + res);
        }

        return dp[amount] = minCoins;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        dp = vector<int>(amount + 1, -1);
        int ans = solve(coins, amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};

// Bottom - Up

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (coin <= i && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
int main()
{
    return 0;
}
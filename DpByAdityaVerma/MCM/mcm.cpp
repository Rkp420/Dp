#include <iostream>
using namespace std;


// Brute - Force

class Solution
{
public:
    int dp[101][101];
    int solve(vector<int> arr, int i, int j)
    {
        if (i >= j)
            return 0;

        int mini = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int cost = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, cost);
        }

        return mini;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        memset(dp, -1, sizeof(dp));

        return solve(arr, 1, n - 1);
    }
};

// Top - down Approach
class Solution
{
public:
    int dp[101][101];
    int solve(vector<int> arr, int i, int j)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int cost = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        memset(dp, -1, sizeof(dp));

        return solve(arr, 1, n - 1);
    }
};

// Bottom - UP

class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++)
        {
            for (int i = 1; i <= n - len; i++)
            {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }

        return dp[1][n - 1];
    }
};


int main()
{
    return 0;
}
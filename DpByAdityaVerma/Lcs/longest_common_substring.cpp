#include <iostream>
using namespace std;

// Simple Recursion
int longestCommonSubstr(string &s1, string &s2, int n, int m, int count)
{
    if (n == 0 || m == 0)
        return 0;

    if (s1[n - 1] == s2[m - 1])
    {
        count = longestCommonSubstr(s1, s2, n - 1, m - 1, count + 1);
    }

    int c1 = longestCommonSubstr(s1, s2, n - 1, m, 0);
    int c2 = longestCommonSubstr(s1, s2, n, m - 1, 0);

    return max({c1, c2, count});
}

// top - down
class Solution
{
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2, int n, int m, int &maxLen)
    {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
        {
            dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, maxLen);
            maxLen = max(maxLen, dp[n][m]);
        }

        solve(s1, s2, n - 1, m, maxLen);
        solve(s1, s2, n, m - 1, maxLen);

        return dp[n][m];
    }

    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();

        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        int maxLen = 0;

        solve(s1, s2, n, m, maxLen);
        return maxLen;
    }
};

// Bottom - Up
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLen = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }

                else
                    dp[i][j] = 0;
            }
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}
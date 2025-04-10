#include <iostream>
using namespace std;
// Leetcode - 1143

// Top - Down 
class Solution
{
public:
    vector<vector<int>> dp;
    int solve(string s1, string s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1);

        else
        {
            return dp[n][m] = max(solve(s1, s2, n, m - 1), solve(s1, s2, n - 1, m));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        dp.clear();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(text1, text2, n, m);
    }
};

// Bottom - Up Approach

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};


int main()
{
    return 0;
}
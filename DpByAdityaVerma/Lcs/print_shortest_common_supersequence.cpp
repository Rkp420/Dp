#include <iostream>
using namespace std;

class Solution
{
public:
    string solve(string s, string p, int n, int m)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        int i = n, j = m;

        while (i > 0 && j > 0)
        {
            if (s[i - 1] == p[j - 1])
            {
                ans.push_back(s[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ans.push_back(s[i - 1]);
                    i--;
                }
                else
                {
                    ans.push_back(p[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0)
            ans.push_back(s[i-- - 1]);
        while (j > 0)
            ans.push_back(p[j-- - 1]);

        // May Written as
        // while (i > 0)
        //     ans.push_back(s[--i]);
        // while (j > 0)
        //     ans.push_back(p[--j]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2)
    {

        int n = str1.size();
        int m = str2.size();

        return solve(str1, str2, n, m);
    }
};

int main()
{
    return 0;
}
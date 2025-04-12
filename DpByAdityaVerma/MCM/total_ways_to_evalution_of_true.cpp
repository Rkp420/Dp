#include <iostream>
using namespace std;

// User function Template for C++
class Solution
{
public:
    int dp[101][101][2];
    int solve(string &s, int i, int j, bool isTrue)
    {
        // Base Case
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lt, lf, rt, rf;
            if (dp[i][k - 1][true] == -1)
                lt = solve(s, i, k - 1, true);
            else
                lt = dp[i][k - 1][true];

            if (dp[i][k - 1][false] == -1)
                lf = solve(s, i, k - 1, false);
            else
                lf = dp[i][k - 1][false];

            if (dp[k + 1][j][true] == -1)
                rt = solve(s, k + 1, j, true);
            else
                rt = dp[k + 1][j][true];

            if (dp[k + 1][j][false] == -1)
                rf = solve(s, k + 1, j, false);
            else
                rf = dp[k + 1][j][false];

            if (s[k] == '^')
            {
                if (isTrue)
                    ans += (lt * rf) + (rt * lf);
                else
                    ans += (lt * rt) + (rf * lf);
            }
            else if (s[k] == '|')
            {
                if (isTrue)
                    ans += (lt * rf) + (lf * rt) + (lt * rt);
                else
                    ans += (lf * rf);
            }
            else
            {
                if (isTrue)
                    ans += (lt * rt);
                else
                    ans += (lf * rt) + (lt * rf) + (lf * rf);
            }
        }

        return dp[i][j][isTrue] = ans;
    }
    int countWays(string &s)
    {
        // code here
        int n = s.size();
        memset(dp, -1, sizeof dp);
        return solve(s, 0, n - 1, true);
    }
};

int main()
{
    return 0;
}
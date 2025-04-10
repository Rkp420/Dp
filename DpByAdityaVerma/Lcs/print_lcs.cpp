#include <iostream>
using namespace std;

string longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans;
    int i = n, j = m;

    while (i > 0 && j > m)
    {

        if (text1[i - 1] == text2[j - 1])
            ans.push_back(text1[i - 1]);
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s1 = "";
    string s2 = "";

    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
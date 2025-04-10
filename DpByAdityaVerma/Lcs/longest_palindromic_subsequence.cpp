#include <iostream>
using namespace std;

class Solution{
    public:
    int longestPalindromicSubsequence(string s){

        string temp = s;
        int n = s.size();
        
        reverse(temp.begin(), temp.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == temp[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};


int main()
{
    return 0;
}
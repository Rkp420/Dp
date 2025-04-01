
// Leetcode -> 2140
#include <iostream>
using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            long long ifsolve = questions[i][0];
            if (i + questions[i][1] + 1 < n)
            {
                ifsolve += dp[i + questions[i][1] + 1]; // Jump correctly
            }
            long long ifnotSolve = dp[i + 1]; // Skip to the next question

            dp[i] = max(ifsolve, ifnotSolve);
        }
        return dp[0]; // The answer is stored in dp[0]
    }
};

int main()
{
    return 0;
}

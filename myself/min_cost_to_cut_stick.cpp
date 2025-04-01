// Leetcode -> 1547
#include <iostream>
using namespace std;

class Solution
{
public:
    int dp[102][102];
    int solve(vector<int> &cuts, int l, int r)
    {
        if (r - l < 2)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int res = INT_MAX;
        for (int i = l + 1; i <= r - 1; i++)
        {
            int cost = (cuts[r] - cuts[l]) + solve(cuts, l, i) + solve(cuts, i, r);

            res = min(res, cost);
        }

        return dp[l][r] = res;
    }

    int minCost(int n, vector<int> &cuts)
    {
        memset(dp, -1, sizeof dp);
        sort(cuts.begin(), cuts.end());

        // adding 0 and n - 1
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int newSize = cuts.size();

        return solve(cuts, 0, newSize - 1);
    }
};

int main()
{
    return 0;
}
#include <iostream>
using namespace std;

// LeetCode : 1155

// Memoised
#define mod (1000000007)
#define ll long long int
class Solution
{
public:
    vector<vector<ll>> dp;
    ll f(int n, int k, int target)
    {
        if (n == 0 && target == 0)
            return 1;
        if (n == 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        ll res = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target - i < 0)
                break;

            res = (res % mod + f(n - 1, k, target - i) % mod) % mod;
        }

        return dp[n][target] = res % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        if (target < n || target > n * k)
            return 0;
        dp.assign(n + 1, vector<ll>(target + 1, -1));
        return f(n, k, target);
    }
};

#define mod 1000000007
#define ll long long int
class Solution
{
public:
    ll fbu(int x, int k, int target)
    {
        vector<vector<ll>> dp(x + 1, vector<ll>(target + 1, 0));

        dp[0][0] = 1;

        for (int dice = 1; dice <= x; dice++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                ll res = 0;
                for (int face = 1; face <= k; face++)
                {
                    if (sum - face >= 0)
                    {
                        res = (res + dp[dice - 1][sum - face]) % mod;
                    }
                }
                dp[dice][sum] = res;
            }
        }

        return dp[x][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        if (target < n || target > n * k)
            return 0;

        return fbu(n, k, target);
    }
};

int main()
{
    return 0;
}
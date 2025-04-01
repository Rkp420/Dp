#include <iostream>
using namespace std;

// Top - Down Approach

class Solution
{
public:
    vector<int> dp;
    int solve(vector<int> &price, int n)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int cut = 0;
        for (int j = 1; j <= n; j++)
        {
            cut = max(cut, price[j - 1] + solve(price, n - j));
        }

        return dp[n] = cut;
    }
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();

        dp = vector<int>(n + 1, -1);
        return solve(price, n);
    }
};


// Bottom - Up Approach

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {

            int maxVal = 0;
            for (int j = 1; j <= i; j++)
            {
                maxVal = max(maxVal, price[j - 1] + dp[i - j]);
            }
            dp[i] = maxVal;
        }

        return dp[n];
    }
};

int main()
{
    return 0;
}

//{ Driver Code Starts

#include <iostream>
using namespace std;

// Memoization

class Solution
{
public:
    bool f(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (i == arr.size())
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];
        if (sum >= arr[i])
        {
            return dp[i][sum] = f(arr, sum - arr[i], i + 1, dp) || f(arr, sum, i + 1, dp);
        }
        else
        {
            return dp[i][sum] = f(arr, sum, i + 1, dp);
        }
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, true));
        for(int i = 1; i <= sum; i++) dp[0][sum] = false;

        for (int i = 1; i <= arr.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[arr.size()][sum];
    }
};

// Bottom - up Approach
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    return 0;
}

// } Driver Code Ends
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;

// Memoisation

class Solution
{

public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr, int sum, int i, int totalSum)
    {
        if (i == arr.size())
        {
            return abs(totalSum - 2 * sum);
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int pick = solve(arr, sum + arr[i], i + 1, totalSum);
        int notPick = solve(arr, sum, i + 1, totalSum);

        return dp[i][sum] = min(pick, notPick);
    }

    int minDifference(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // We only need sum up to totalSum/2, reducing space complexity
        int target = totalSum / 2;
        dp.resize(n + 1, vector<int>(target + 1, -1));
        return solve(arr, 0, 0, totalSum);
    }
};

// Simple Recursive

class Solution
{

public:

    int solve(vector<int> &arr, int sum, int i, int totalSum)
    {
        if (i == arr.size())
        {
            return abs(totalSum - 2 * sum);
        }


        int pick = solve(arr, sum + arr[i], i + 1, totalSum);
        int notPick = solve(arr, sum, i + 1, totalSum);

        return min(pick, notPick);
    }

    int minDifference(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        int totalSum = 0;
        for(int &num : arr) totalSum += num;
        return solve(arr, 0, 0, totalSum);
    }
};

// Bottom Up

class Solution
{

public:
    int minDifference(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {

                bool notPick = dp[i - 1][j];

                bool pick = false;
                if (j >= arr[i - 1])
                {
                    pick = dp[i - 1][j - arr[i - 1]];
                }

                dp[i][j] = pick || notPick;
            }
        }

        int closestSum = 0;
        for (int j = target; j >= 0; j--)
        {
            if (dp[n][j])
            {
                closestSum = j;
                break;
            }
        }

        return abs(totalSum - 2 * closestSum);
    }
};

// Space Optimised
class Solution
{

public:
    int minDifference(vector<int> &arr)
    {
        // Your code goes here
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum / 2;
        vector<bool>dp (target + 1, false);

        dp[0] = true;

        for(int &num : arr){
            for(int j = target; j >= 0; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int closestSum = 0;
        for (int j = target; j >= 0; j--)
        {
            if (dp[j])
            {
                closestSum = j;
                break;
            }
        }

        return abs(totalSum - 2 * closestSum);
    }
};

int main()
{
    return 0;
}
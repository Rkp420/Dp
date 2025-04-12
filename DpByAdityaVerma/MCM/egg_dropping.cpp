#include <iostream>
using namespace std;

// Using Binary Search
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int dp[1003][1003];
    int solve(int egg, int floor)
    {
        if (floor == 0 || floor == 1)
            return floor;
        if (egg == 1)
            return floor;

        if (dp[egg][floor] != -1)
            return dp[egg][floor];

        int mini = INT_MAX;
        int low = 1, high = floor;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (dp[egg - 1][mid - 1] == -1)
                dp[egg - 1][mid - 1] = solve(egg - 1, mid - 1);

            if (dp[egg][floor - mid] == -1)
                dp[egg][floor - mid] = solve(egg, floor - mid);

            int breakEgg = dp[egg - 1][mid - 1];
            int noBreak = dp[egg][floor - mid];
            int temp = 1 + max(breakEgg, noBreak);

            if (breakEgg > noBreak)
                high = mid - 1;
            else
                low = mid + 1;

            mini = min(mini, temp);
        }

        return dp[egg][floor] = mini;
    }
    int eggDrop(int n, int k)
    {
        // code here
        memset(dp, -1, sizeof dp);
        return solve(n, k);
    }
};

// Using Linear Search
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int dp[1003][1003];
    int solve(int egg, int floor)
    {
        if (floor == 0 || floor == 1)
            return floor;
        if (egg == 1)
            return floor;

        if (dp[egg][floor] != -1)
            return dp[egg][floor];

        int mini = INT_MAX;
        for (int k = 1; k <= floor; k++)
        {
            int temp = 0;
            if (dp[egg - 1][k - 1] == -1)
                dp[egg - 1][k - 1] = solve(egg - 1, k - 1);
            if (dp[egg][floor - k] == -1)
                dp[egg][floor - k] = solve(egg, floor - k);

            temp = 1 + max(dp[egg - 1][k - 1], dp[egg][floor - k]);

            mini = min(mini, temp);
        }

        return dp[egg][floor] = mini;
    }
    int eggDrop(int n, int k)
    {
        // code here
        memset(dp, -1, sizeof dp);
        return solve(n, k);
    }
};

int main()
{
    return 0;
}
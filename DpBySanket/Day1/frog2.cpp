#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int k = 3;
vector<int> cost;

// Recursive Approach
int f(int i)
{
    if (i >= cost.size())
        return INT_MAX; // Out of bounds
    if (i == cost.size() - 1)
        return 0; // Reached last stone

    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i + j >= cost.size())
            break;
        int jump_cost = f(i + j);
        if (jump_cost != INT_MAX) // Prevent overflow
            ans = min(ans, abs(cost[i] - cost[i + j]) + jump_cost);
    }

    return ans;
}

// Memoization
vector<int> dp; // Declare dp globally but initialize later
int ftd(int i)
{
    if (i >= cost.size())
        return INT_MAX;
    if (i == cost.size() - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i]; // Memoized result

    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i + j >= cost.size())
            break;
        int jump_cost = ftd(i + j);
        if (jump_cost != INT_MAX)
            ans = min(ans, abs(cost[i] - cost[i + j]) + jump_cost);
    }

    return dp[i] = ans;
}

// Bottom-Up DP
int fbu()
{
    int n = cost.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0; // Base case

    for (int j = n - 2; j >= 0; j--)
    {
        for (int step = 1; step <= k; step++)
        {
            if (j + step < n)
            {
                dp[j] = min(dp[j], abs(cost[j] - cost[j + step]) + dp[j + step]);
            }
        }
    }

    return dp[0];
}

int frogJumpOptimized()
{
    int n = cost.size();
    int prev = 0, prev2 = INT_MAX; // Equivalent to dp[n-1] and dp[n-2]

    for (int i = n - 2; i >= 0; i--)
    {
        int cur = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i + j < n)
            {
                cur = min(cur, abs(cost[i] - cost[i + j]) + prev);
            }
        }
        prev2 = prev;
        prev = cur;
    }

    return prev; // Equivalent to dp[0]
}

int main()
{
    int n;
    cin >> n;

    cost.resize(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    // Initialize dp array for memoization
    dp.assign(n, -1);

    // Print results for different approaches
    cout << "Recursive: " << f(0) << endl;
    cout << "Memoization: " << ftd(0) << endl;
    cout << "Bottom-Up: " << fbu() << endl;

    return 0;
}
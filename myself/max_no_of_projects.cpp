#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dp; // Use long long to avoid overflow

int findLastNonOverlapping(vector<vector<int>> &projects, int i)
{
    int lo = 0, hi = i - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (projects[mid][1] < projects[i][0])
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

long long solve(vector<vector<int>> &projects, int i)
{
    if (i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int idx = findLastNonOverlapping(projects, i);

    long long take = (long long)projects[i][2] + solve(projects, idx); // Cast to avoid overflow
    long long notChoose = solve(projects, i - 1);

    return dp[i] = max(take, notChoose);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    sort(projects.begin(), projects.end(), [](const vector<int> &a, const vector<int> &b)
         {
             return a[1] < b[1]; // Sort by end time
         });

    dp.assign(n, -1); // Initialize dp with -1

    cout << solve(projects, n - 1) << endl;

    return 0;
}
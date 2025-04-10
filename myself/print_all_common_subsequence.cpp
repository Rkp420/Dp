#include <iostream>
#include <set>
#include <map>
using namespace std;

vector<vector<int>> dp;
map<pair<int, int>, set<string>> memo;

void build_dp(string s, string t, int n, int m)
{
    dp.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

set<string> backTrack(string &s, string &t, int i, int j)
{
    if (i == 0 || j == 0)
        return {""};

    pair<int, int> key = {i, j};
    if(memo.count(key)){
        return memo[key];
    }

    set<string> result;
    if (s[i - 1] == t[j - 1])
    {
        set<string> temp = backTrack(s, t, i - 1, j - 1);
        for (string str : temp)
            result.insert(str + s[i - 1]);
    }
    else
    {
        if (dp[i - 1][j] == dp[i][j])
        {
            set<string> temp = backTrack(s, t, i - 1, j);
            result.insert(temp.begin(), temp.end());
        }

        if (dp[i][j-1] == dp[i][j])
        {
            set<string> temp = backTrack(s, t, i, j - 1);
            result.insert(temp.begin(), temp.end());
        }
    }

    return memo[key] = result;
}

vector<string> all_longest_common_subsequences(string s, string t)
{
    int n = s.size();
    int m = t.size();

    // Clear All 
    dp.clear();
    memo.clear();
    
    // Step 1 : Make a dp Table
    build_dp(s, t, n, m);

    // Step 2 : Start BackTrack from dp[n][m]
    set<string> allLcs = backTrack(s, t, n, m);

    // Step 3 : Return all the Values 
    return vector<string> (allLcs.begin(), allLcs.end());
}

int main()
{
    return 0;
}
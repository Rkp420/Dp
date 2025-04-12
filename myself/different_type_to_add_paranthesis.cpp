#include <iostream>
using namespace std;

// https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution
{
public:
    unordered_map<string, vector<int>> dp;
    vector<int> solve(string s, int i, int j)
    {
        string key = s.substr(i, j - i + 1);
        if (dp.count(key))
            return dp[key];

        vector<int> res;
        for (int k = i; k <= j; k++)
        {
            if (s[k] == '-' || s[k] == '+' || s[k] == '*')
            {
                vector<int> left = solve(s, i, k - 1);
                vector<int> right = solve(s, k + 1, j);

                for (int l : left)
                {
                    for (int r : right)
                    {
                        if (s[k] == '-')
                            res.push_back(l - r);
                        else if (s[k] == '*')
                            res.push_back(l * r);
                        else
                            res.push_back(l + r);
                    }
                }
            }
        }

        if (res.empty())
        {
            int num = stoi(s.substr(i, j - i + 1));
            res.push_back(num);
        }

        return dp[key] = res;
    }

    vector<int> diffWaysToCompute(string expression)
    {
        dp.clear();
        int n = expression.size();
        return solve(expression, 0, n - 1);
    }
};

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> nums;
        vector<char> ops;

        // Step 1: Parse expression
        int num = 0;
        for (int i = 0; i < expression.size(); i++)
        {
            if (isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
            }
            else
            {
                nums.push_back(num);
                ops.push_back(expression[i]);
                num = 0;
            }
        }
        nums.push_back(num); // last number

        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        // Step 2: Fill base cases (gap = 0)
        for (int i = 0; i < n; i++)
        {
            dp[i][i].push_back(nums[i]);
        }

        // Step 3: Fill dp table (gap-based)
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0; i < n - gap; i++)
            {
                int j = i + gap;

                for (int k = i; k < j; k++)
                {
                    for (int left : dp[i][k])
                    {
                        for (int right : dp[k + 1][j])
                        {
                            if (ops[k] == '+')
                                dp[i][j].push_back(left + right);
                            else if (ops[k] == '-')
                                dp[i][j].push_back(left - right);
                            else if (ops[k] == '*')
                                dp[i][j].push_back(left * right);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
int main()
{
    return 0;
}
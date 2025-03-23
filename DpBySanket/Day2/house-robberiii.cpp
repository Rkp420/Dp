#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// simple Recursive
class Solution
{
public:
    vector<int> maxRob(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        vector<int> left = maxRob(root->left);
        vector<int> right = maxRob(root->right);

        vector<int> ans(2);
        // Option 1 : Rob this House
        ans[0] = root->val + left[1] + right[1];

        // Option 2 : Skip This House
        ans[1] = max({left[1] + right[0], left[0] + right[1],
                      left[0] + right[0], left[1] + right[1]});

        return ans;
    }

    int rob(TreeNode *root)
    {
        vector<int> ans(2, 0);
        ans = maxRob(root);

        return max(ans[0], ans[1]);
    }
};

// Simple Memoised
class Solution
{
public:
    unordered_map<TreeNode *, vector<int>> dp;
    vector<int> maxRob(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        if (dp.find(root) != dp.end())
            return dp[root];

        vector<int> left = maxRob(root->left);
        vector<int> right = maxRob(root->right);

        vector<int> ans(2);
        // Option 1 : Rob this House
        ans[0] = root->val + left[1] + right[1];

        // Option 2 : Skip This House
        ans[1] = max({left[1] + right[0], left[0] + right[1],
                      left[0] + right[0], left[1] + right[1]});

        return dp[root] = ans;
    }

    int rob(TreeNode *root)
    {
        vector<int> ans(2, 0);
        ans = maxRob(root);
        return max(ans[0], ans[1]);
    }
};

int main()
{
    return 0;
}
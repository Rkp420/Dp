#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    int solve(Node *root, int &res)
    {
        if (!root)
            return 0;

        // If it's a leaf node, just return its value
        if (!root->left && !root->right)
            return root->data;

        int left = solve(root->left, res);
        int right = solve(root->right, res);

        // If both children exist, this can be a valid leaf-to-leaf path
        if (root->left && root->right)
        {
            res = max(res, left + right + root->data);
            return max(left, right) + root->data;
        }

        // If only one child exists, return that path + root
        return root->left ? left + root->data : right + root->data;
    }
    int maxPathSum(Node *root)
    {
        int res = INT_MIN;
        int val = solve(root, res);

        // Handle edge case: only one leaf exists
        if (!root->left || !root->right)
            return max(res, val);

        return res;
    }
};

int main()
{
    return 0;
}
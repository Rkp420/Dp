#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    int solve(Node *root, int &sum)
    {
        if (root == NULL)
            return 0;

        int left = solve(root->left, sum);
        int right = solve(root->right, sum);

        // Case 1: max path using either left or right or just root
        int temp1 = max({left + root->data, right + root->data, root->data});

        // Case 2: path passing through root and both children
        int temp2 = left + right + root->data;

        // Update global max
        sum = max({sum, temp1, temp2});

        return temp1;
    }

    int findMaxSum(Node *root)
    {
        int sum = INT_MIN; // handles all-negative trees
        solve(root, sum);
        return sum;
    }
};

class Solution
{
public:
    // Function to return maximum path sum from any node in a tree.
    int solve(Node *root, int &sum, int &mini)
    {
        if (root == NULL)
            return 0;

        mini = max(root->data, mini);

        int left = solve(root->left, sum, mini);
        int right = solve(root->right, sum, mini);

        // Case 1 :
        int temp1 = max(max(left, right) + root->data, root->data);

        // Case 2 :
        int temp2 = left + right + root->data;

        int tempAns = max(temp1, temp2);

        sum = max(sum, tempAns);

        return temp1;
    }
    int findMaxSum(Node *root)
    {
        // code here
        int sum = 0;
        int mini = INT_MIN;

        int temp = solve(root, sum, mini);

        if (sum == 0)
            return mini;
        return sum;
    }
};

int main()
{
    return 0;
}
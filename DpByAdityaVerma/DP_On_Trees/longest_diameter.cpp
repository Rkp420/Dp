#include <iostream>
using namespace std;

/**
 * ❓ Is Memoization Required Here?

     Actually — memoization isn’t needed in this specific case!

    Why?
    •	You’re doing a postorder traversal (solve() calls left, then right, then processes current node).
    •	In this traversal, each node is visited only once, and no subproblem is repeated.
    •	So the use of unordered_map<Node*, int> adds extra space and overhead without helping time complexity.
 */


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

class Solution
{
public:
    unordered_map<Node *, int> dp;
    int solve(Node *root, int &res)
    {
        if (root == NULL)
            return 0;

        if (dp.count(root))
            return dp[root];

        int left = solve(root->left, res);
        int right = solve(root->right, res);

        // Case 1 :
        int temp1 = 1 + max(left, right);

        // Case 2 :
        int temp2 = 1 + left + right;
        int tempAns = max(temp1, temp2);

        res = max(tempAns, res);

        // You are Forced to return this
        return dp[root] = temp1;
    }
    int diameter(Node *root)
    {
        // Your code here
        int res = INT_MIN;
        int temp = solve(root, res);
        return res - 1;
    }
};

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution
{
public:
    int solve(Node *root, int &res)
    {
        if (root == NULL)
            return 0;

        int left = solve(root->left, res);
        int right = solve(root->right, res);

        // Case 1 :
        int temp1 = 1 + max(left, right);

        // Case 2 :
        int temp2 = 1 + left + right;
        int tempAns = max(temp1, temp2);

        res = max(tempAns, res);

        // You are Forced to return this
        return temp1;
    }
    int diameter(Node *root)
    {
        // Your code here
        int res = INT_MIN;
        int temp = solve(root, res);
        return res - 1;
    }
};

int main()
{
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> result;

    void generate(int open, int close, string curr, int n)
    {
        if (open == n && close == n)
        {
            result.push_back(curr);
            return;
        }

        if (open < n)
            generate(open + 1, close, curr + '[', n);
        if (close < open)
            generate(open, close + 1, curr + ']', n);
    }

    vector<string> generateAllValidBrackets(int n)
    {
        result.clear();
        generate(0, 0, "", n);
        return result;
    }
};

int main()
{
    Solution s;
    int n = 2;

    vector<string> ans = s.generateAllValidBrackets(n);

    for (const string &str : ans)
    {
        cout << str << endl;
    }

    return 0;
}
// Leetcode -> 3219
#include <iostream>
using namespace std;

class Solution
{
public:
    long long minimumCost(int m, int n, vector<int> &horizontalCut,
                          vector<int> &verticalCut)
    {

        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int i = 0, j = 0;

        int horizontalPeices = 1;
        int verticalPeices = 1;
        long long ans = 0;
        while (i < m - 1 && j < n - 1)
        {
            if (horizontalCut[i] >= verticalCut[j])
            {
                ans += (horizontalCut[i] * verticalPeices);
                horizontalPeices++;
                i++;
            }
            else
            {
                ans += (verticalCut[j] * horizontalPeices);
                verticalPeices++;
                j++;
            }
        }

        while (i < m - 1)
        {
            ans += (horizontalCut[i++] * verticalPeices);
        }

        while (j < n - 1)
        {
            ans += (verticalCut[j++] * horizontalPeices);
        }

        return ans;
    }
};

int main()
{
    return 0;
}
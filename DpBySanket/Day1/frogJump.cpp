#include <iostream>
using namespace std;
class Solution
{
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    bool mayCross(int curr_stone_idx, vector<int> &stones, int lastJump)
    {
        if (curr_stone_idx == n - 1)
            return true;

        if (t[curr_stone_idx][lastJump] != -1)
            return t[curr_stone_idx][lastJump];

        // There Are Three Options
        bool res = false;
        for (int j = lastJump - 1; j <= lastJump + 1; j++)
        {

            if (j > 0)
            {
                int nextJump = stones[curr_stone_idx] + j;
                if (mp.find(nextJump) != mp.end())
                {
                    res = res || mayCross(mp[nextJump], stones, j);
                }
            }
        }

        return t[curr_stone_idx][lastJump] = res;
    }
    bool canCross(vector<int> &stones)
    {
        n = stones.size();

        if (stones[1] != 1)
            return false;

        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        memset(t, -1, sizeof(t));
        return mayCross(0, stones, 0);
    }
};

int main()
{
    return 0;
}
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> palMemo;
        vector<vector<int>> dp;
        bool isPalindrome(string &s, int i, int j){
            if(palMemo[i][j] != -1) return palMemo[i][j] == 1;

            while(i < j){
                if(s[i] != s[j]) return palMemo[i][j] = 0;
                i++;
                j--;
            }

            return palMemo[i][j] = 1;
        }

        int solve(string &s, int i, int j){
            if(i >= j) return 0;

            if(dp[i][j] != -1) return dp[i][j];
            if(isPalindrome(s, i, j)) return dp[i][j] = 0;

            int res = INT_MAX;
            for(int k = i; k < j; k++){
                int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
                res = min(res, temp);
            }

            return dp[i][j] = res;
        }

        int minimumPartition(string s){
            int n = s.size();
            palMemo.clear();
            palMemo.resize(n, vector<int>(n, -1));

            dp.clear();
            dp.resize(n + 1, vector<int> (n + 1, -1));

            return solve(s, 0, n -1);
        }
};
int main()
{
    return 0;
}
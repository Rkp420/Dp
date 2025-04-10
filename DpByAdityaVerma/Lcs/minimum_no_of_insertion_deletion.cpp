#include <iostream>
using namespace std;

// Minimum No of insertions and deletions to make two different string identical
class Solution {
    public:
    vector<int> minInsertionAndDeletion(string s1, string s2){

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int minDeletion = n - dp[n][m];
        int minInsertion = m - dp[n][m];

        return {minInsertion, minDeletion};
    }
};

int main()
{
    return 0;
}
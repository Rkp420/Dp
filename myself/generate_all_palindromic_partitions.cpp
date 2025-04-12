#include <iostream>
using namespace std;

// Generating All Palindromic Partioning Possible 
// Using BackTracking
class Solution{
    vector<vector<string>> ans;

    bool isPalindrome(string s, int i , int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string s, int i, vector<string> path){
        if(i == s.size()){
            ans.push_back(path);
            return;
        }

        for(int k = i; k < s.size(); k++){
            if(isPalindrome(s, i , k)){
                path.push_back(s.substr(i, k  - i + 1));
                solve(s, i + 1, path);
                path.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> generateAllPalindromicPartitions(string s){
        ans.clear();

        vector<string> path;
        solve(s, 0, path);

        return ans;
    }
};

// Trying to Memoise it
class Solution
{
    vector<vector<string>> result;

    unordered_map<int, vector<vector<string>>> dp; 

    bool isPalindrome(int i , int j, const string &s, vector<vector<int>> &palMemo){
        if(palMemo[i][j] != -1) return palMemo[i][j];

        while(i < j){
            if(s[i] != s[j]) return palMemo[i][j] = 0;
            i++;
            j--;
        }

        return palMemo[i][j] = 1;
    }

    vector<vector<string>> solve(int index, string &s,vector<vector<int>> &palMemo)
    {
        if(dp.find(index) != dp.end()) return dp[index];

        if (index == s.size()) return {{}};

        vector<vector<string>> partitions;

        for (int k = index; k < s.size(); k++)
        {
            if (isPalindrome(index, k , s, palMemo))
            {
                string current = s.substr(index, k - index + 1);
                vector<vector<string>> rest = solve(k + 1, s, palMemo);
                for(auto &r : rest) {
                    vector<string> temp = {current};
                    for(string some : r) temp.push_back(some);
                    partitions.push_back(temp);
                }
            }
        }

        return dp[index] = partitions;
    }
    vector<vector<string>> generateAllPalindromicPartitions(string s)
    {
        result.clear();
        dp.clear();
        int n = s.size();
        vector<vector<int>> palMemo(n, vector<int>(n, -1)); // -1 = unknown, 0 = false, 1 = true

        return solve(0, s, palMemo);
    }
};


int main()
{
    return 0;
}
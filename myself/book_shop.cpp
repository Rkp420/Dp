#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector<vector<int>> dp;
// int solve(vector<int>& price, vector<int>& pages, int i, int x){
//     if(i == price.size()) return 0;

//     if(dp[i][x] != -1) return dp[i][x];

//     int notTake = solve(price, pages, i + 1, x);
//     int take = 0;
//     if(price[i] <= x) take = pages[i] + solve(price, pages, i + 1, x - price[i]);

//     return dp[i][x] = max(take, notTake);
// }

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);

    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}
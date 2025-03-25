#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> coin;
vector<int> dp(1000005, -2);

int f(int n){
    if(n == 0) return 0;

    int res = INT_MAX;
    for(int i = 0; i < coin.size(); i++){
        res = min(res , f(n - coin[i]));
    }

    if(res == INT_MAX) return -1;

    return 1 + res;
}

// top down
int ftd(int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != -2)
        return dp[n];

    int res = INT_MAX;
    for (int i = 0; i < coin.size(); i++)
    {
        if(n - coin[i] < 0) continue;
        res = min(res, ftd(n - coin[i]));
    }

    if (res == INT_MAX)
        return dp[n] = INT_MAX;

    return dp[n] = 1 + res;
}

int main()
{
    int n;
    int x;
    cin >> n >> x;
    // coin.resize(n, 0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        coin.push_back(num);
    }

    int ans = ftd(x);

    if(ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
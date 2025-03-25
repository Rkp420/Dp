#include <iostream>
#include <vector>
using namespace std;

int f(int n, int l, int k)
{
    if (n == 1 || n == k || n == l)
        return 1; // A wins immediately
    if (n <= 0)
        return 0; // If no valid moves, A loses, so B wins

    return (f(n - 1, l, k) == 0 || (n - k >= 0 && f(n - k, l, k) == 0) || (n - l >= 0 && f(n - l, l, k) == 0));
}

int main()
{
    int k, l , m;
    // m -> no of games
    cin >> k >> l >> m;
    
    vector<int> coins(m);
    for(int i = 0; i < m; i++){
        cin >> coins[i];
    }

    // Time to Solve Step by Step
    // Step 1 : Prepare Already Your ans Array For Highest Possible value of Coins
    vector<int> dp(1000005, 0);

    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;

    for(int i = 2; i <= 1000000; i++){
        if(i == k || i == l) continue;
        dp[i] = !(dp[i - 1] && (i - k > 0 ? dp[i - k] : 1) && (i - l > 0 ? dp[i - l] : 1));
    }

    for(int i = 0; i < m; i++){
        if(f(coins[i],l , k)) cout <<"A";
        else cout << "B";
    }

    return 0;
}
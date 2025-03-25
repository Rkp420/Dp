#include <iostream>
#include <vector>
#include <climits>
#define mod 1000000007
#define ll long long int
using namespace std;
int f1(int n)
{
    if (n == 1 || n == 2 || n == 0)
        return n;

    int res = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;
        ;
        res = res + f1(n - i);
    }
    return 1 + res;
}

int f2(int n)
{
    if (n == 0)
        return 1;

    int res = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;

        res = res + f2(n - i);
    }
    return res;
}

vector<ll> dp(1000006, -1);
ll ftd(int n)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll res = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;

        res = (res % mod + ftd(n - i) % mod) % mod;
    }
    return dp[n] = res % mod;
}

ll fbu(int n)
{
    vector<ll> dp(n + 1, 0);
    dp[0] = 1; // Correct base case

    for (int i = 1; i <= n; i++)
    {
        ll res = 0;
        for (int j = 1; j <= 6; j++)
        {
            if (i - j < 0)
                break;

            res = (res % mod + dp[i - j]) % mod;
        }

        dp[i] = res % mod;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << ftd(n) << "\n";
    cout << fbu(n) << "\n";
    return 0;
}
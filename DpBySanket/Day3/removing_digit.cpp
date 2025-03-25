#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// BruteForce : Recursive
vector<int> dp(1000005, -1);
vector<int> get_digits(int n)
{
    vector<int> res;
    while (n > 0)
    {
        if (n % 10 != 0)
            res.push_back(n % 10);

        n /= 10;
    }

    return res;
}

int f(int n)
{
    if (n == 0)
        return 0;
    if (n <= 9)
        return 1;

    vector<int> d = get_digits(n);

    int res = INT_MAX;
    for(int i = 0; i < d.size(); i++){
        res = min(res, f(n - d[i]));
    }

    return 1 + res;
}

// Memoisation
int ftd(int n)
{
    if (n == 0)
        return 0;
    if (n <= 9)
        return 1;

    if(dp[n] != -1) return dp[n];
    vector<int> d = get_digits(n);

    int res = INT_MAX;
    for (int i = 0; i < d.size(); i++)
    {
        res = min(res, ftd(n - d[i]));
    }

    return dp[n] = 1 + res;
}

int main()
{
    int n;
    cin >> n;
    cout<<ftd(n) << "\n";
    return 0;
}
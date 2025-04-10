#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

typedef long long ll;

// Two large primes
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int P1 = 911;
const int P2 = 3571;

pair<ll, ll> getHash(const string &s, int start, int len, ll power1, ll power2, ll mod1, ll mod2)
{
    ll hash1 = 0, hash2 = 0;
    for (int i = start; i < start + len; i++)
    {
        hash1 = (hash1 * P1 + s[i]) % MOD1;
        hash2 = (hash2 * P2 + s[i]) % MOD2;
    }
    return {hash1, hash2};
}

bool hasCommonSubstring(const string &s1, const string &s2, int len)
{
    if (len == 0)
        return true;

    unordered_set<ll> hashes;

    ll hash1 = 0, hash2 = 0, power1 = 1, power2 = 1;

    // Precompute powers
    for (int i = 0; i < len; i++)
    {
        power1 = (power1 * P1) % MOD1;
        power2 = (power2 * P2) % MOD2;
    }

    unordered_set<ll> seen;

    // Hash substrings of s1
    hash1 = hash2 = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        hash1 = (hash1 * P1 + s1[i]) % MOD1;
        hash2 = (hash2 * P2 + s1[i]) % MOD2;

        if (i >= len)
        {
            hash1 = (hash1 - s1[i - len] * power1 % MOD1 + MOD1) % MOD1;
            hash2 = (hash2 - s1[i - len] * power2 % MOD2 + MOD2) % MOD2;
        }

        if (i >= len - 1)
        {
            seen.insert(hash1 * 1LL * MOD2 + hash2); // combine both hashes into one number
        }
    }

    // Hash substrings of s2 and check
    hash1 = hash2 = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        hash1 = (hash1 * P1 + s2[i]) % MOD1;
        hash2 = (hash2 * P2 + s2[i]) % MOD2;

        if (i >= len)
        {
            hash1 = (hash1 - s2[i - len] * power1 % MOD1 + MOD1) % MOD1;
            hash2 = (hash2 - s2[i - len] * power2 % MOD2 + MOD2) % MOD2;
        }

        if (i >= len - 1)
        {
            ll combined = hash1 * 1LL * MOD2 + hash2;
            if (seen.count(combined))
                return true;
        }
    }

    return false;
}

int longestCommonSubstring(string s1, string s2)
{
    int left = 0, right = min(s1.size(), s2.size()), ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (hasCommonSubstring(s1, s2, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int res = longestCommonSubstring(s1, s2);
    cout << res << endl;

    return 0;
}
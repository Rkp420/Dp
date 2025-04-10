#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> days(n + 5, 0);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        days[l]++;
        days[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
    { // FIXED boundary
        days[i] += days[i - 1];
    }

    int maxCoins = 0;
    for (int i = 0; i <= n; i++)
    {
        maxCoins = max(maxCoins, days[i]);
    }

    vector<int> c(maxCoins + 2, 0); // dynamic size
    for (int i = 0; i <= n; i++)
    {
        int coins = days[i];
        c[coins]++;
    }

    for (int i = maxCoins; i >= 0; i--)
    {
        c[i] += c[i + 1];
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i];

    for (int i = 0; i < q; i++)
    { // FIXED from m to q
        if (queries[i] <= maxCoins)
            cout << c[queries[i]] << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
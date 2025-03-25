#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }

    // Step 1 : Initialisation
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int day = 1; day < n; day++){
        dp[day][0] = v[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
        dp[day][1] = v[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
        dp[day][2] = v[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    return 0;
}
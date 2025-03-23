#include <iostream>
#include <vector>
using namespace std;

// BruteForce Approach 
int fib(int n) {
    if(n == 0 || n == 1) return n;

    return fib(n -1) + fib(n - 2);
}

// Memoised Approach Or Top - Down Approach

vector<int> dp;
int f(int n){
    if(n == 0 || n == 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n - 1) + f(n -2);
}

// Bottom - Up Approach (Iterative Approach)
int fun(int n){

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimised
int func(int n){

    if (n == 0 || n == 1)
        return n;

    int a = 0;
    int b = 1;
    int c;
    int i = 2;
    while(i <= n){
        c = a + b;
        a = b;
        b = c;
        i++;
    }

    return c;
}

int main()
{
    int n;
    cin >> n;
    dp.clear();
    dp.resize(n + 1, -1);
    return 0;
}
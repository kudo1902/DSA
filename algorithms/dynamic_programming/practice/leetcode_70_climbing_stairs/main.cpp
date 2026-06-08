#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    return solve(n, dp);
}

int main()
{
    freopen("output.txt", "w", stdout);
    cout << climbStairs(2) << '\n';
    cout << climbStairs(3) << '\n';
    cout << climbStairs(4) << '\n';
    return 0;
}

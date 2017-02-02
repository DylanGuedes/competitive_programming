#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int n, m;
int dp[102][102];
int girl[102];
int boy[102];
int solve(int b, int g)
{
    if (b==n || g==m)
        return 0;

    if (dp[b][g] != -1)
        return dp[b][g];

    int ans = 0;
    if (abs(boy[b]-girl[g]) <= 1) {
        ans = max(1+solve(b+1, g+1), solve(b+1, g));
        ans = max(ans, solve(b, g+1));
    } else {
        ans = max(solve(b+1, g), solve(b, g+1));
    }

    return dp[b][g] = ans;
}

int main()
{
    cin >> n;
    FOR(i, 0, n) {
        cin >> boy[i];
    }
    cin >> m;
    FOR(i, 0, m) {
        cin >> girl[i];
    }
    sort(boy, boy+n);
    sort(girl, girl+m);
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;

    return 0;
}

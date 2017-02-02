#include <iostream>
#include <cstring>

using namespace std;

int arr[51];
int dp[50][50];
int n, m;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int solve(int idx, int remaining, int maxval, int minval)
{
    if (remaining == 0) {
        return maxval-minval;
    }

    if (idx == m)
        return 0xffffff;


    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    int ans = solve(idx+1, remaining, maxval, minval);
    int ans2 = solve(idx+1, remaining-1, max(maxval, arr[idx]), min(minval, arr[idx]));

    return dp[idx][remaining] = min(ans, ans2);
}

int main()
{
    scanf("%d%d", &n, &m);
    FOR(i, 0, m) {
        scanf("%d", &arr[i]);
    }

    memset(dp, -1, sizeof dp);

    printf("%d\n", solve(0, n, -0xffffff, 0xffffff));
    return 0;
}

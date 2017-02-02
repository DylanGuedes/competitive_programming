#include <bits/stdc++.h>

using namespace std;

int a[105];
int n;

const int contest = 2;
#define repi(i, j, k)for(int i=j;i<k;++i)
const int gym = 4;
int dp[105][5];

int solve(int idx, int state)
{
        if (idx == n)
                return 0;
        int ans = 1<<30;

        if (dp[idx][state] != -1)
                return dp[idx][state];

        if (a[idx]==0) {
                return dp[idx][state] = solve(idx+1, 0)+1;
        } else if (a[idx] == 1) {
                if (contest&state) {
                        return dp[idx][state] = solve(idx+1, 0)+1;
                } else {
                        return dp[idx][state] = solve(idx+1, contest);
                }
        } else if (a[idx] == 2) {
                if (gym&state) {
                        return dp[idx][state] = solve(idx+1, 0)+1;
                } else {
                        return dp[idx][state] = solve(idx+1, gym);
                }
        } else if (a[idx] == 3) {
                if (gym&state) {
                        return dp[idx][state] = solve(idx+1, contest);
                } else if (contest&state) {
                        return  dp[idx][state] = solve(idx+1, gym);
                } else {
                        return dp[idx][state] = min(solve(idx+1, contest), solve(idx+1, gym));
                }
        }

        return ans;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        repi(i, 0, n)
                cin >> a[i];

        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << "\n";
        return 0;
}

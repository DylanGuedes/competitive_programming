#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m;

#define N 305
#define M 305
int pies[N][M];
ll dp[N][M];

ll solve(int idx, int factor)
{
        if (factor == 0) {
                return 0;
        }
        if (dp[idx][factor]!=-1) {
                return dp[idx][factor];
        }
        ll extra = factor > m ? factor-m : 0;
        ll aggr=0;
        rep(j, 0, factor-extra) {
                aggr+=pies[idx][j];
        }

        ll sol = (ll)1<<60;
        for (int i=factor-extra; i>=1; i--) {
                sol = min(sol, solve(idx+1, factor-i)+aggr+(i*i));
                aggr-=pies[idx][i-1];
        }

        return dp[idx][factor] = sol;
}

int main()
{
        ios::sync_with_stdio(false);

        int t;
        cin >> t;
        rep(z, 1, t+1) {
                memset(dp, -1, sizeof dp);
                cout << "Case #" << z<<": ";
                cin >> n >> m;
                rep(i, 0, n) {
                        rep(j, 0, m) {
                                cin >> pies[i][j];
                        }
                        sort(pies[i], pies[i]+m);
                }

                // return 0;
                cout << solve(0, n) << "\n";
        }
        return 0;
}

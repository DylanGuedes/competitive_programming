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

int n, m, fam;
int lo, hi, foo;

#define N 110
#define K 5005

int dist[N][N];
int ini[N];
int fim[N];
int dp[K][N][3];

int solve(int idx, int node, int len)
{
        if (dp[idx][node][len] != -1) {
                return dp[idx][node][len];
        }
        int ans=1<<30;

        if (idx == fam) {
                if (len==1) {
                        ans = dist[node][fim[idx-1]];
                } else if (len==2) {
                        ans = dist[node][fim[idx-2]]+dist[fim[idx-2]][fim[idx-1]];
                } else {
                        return 0;
                }
        } else {
                if (len == 0) {
                        if (dist[node][ini[idx]] >= 1<<30) {
                                return 1<<30;
                        } else {
                                ans = solve(idx+1, ini[idx], 1)+dist[node][ini[idx]];
                        }
                } else if (len == 1) {
                        // pega o proximo
                        ans = solve(idx+1, ini[idx], 2)+dist[node][ini[idx]];

                        // entrega o empilhado
                        ans = min(ans, solve(idx, fim[idx-1], 0)+dist[node][fim[idx-1]]);
                } else if (len == 2) {
                        // entrega o empilhado
                        ans = solve(idx, fim[idx-2], 1)+dist[node][fim[idx-2]];
                }
        }

        // cout << "s("<<idx<< ", "<<node<<", "<<len<<") = " << ans << "\n";
        return dp[idx][node][len]=ans;
}

int main()
{
        ios::sync_with_stdio(false);

        int t;
        cin >> t;
        rep(z, 1, t+1) {
                cout << "Case #"<<z<<": ";
                cin >> n >> m >> fam;
                memset(dist, 0x3F, sizeof dist);
                memset(dp, -1, sizeof dp);

                rep(i, 0, n+5) {
                        dist[i][i]=0;
                }
                rep(i, 0, m) {
                        cin >> lo >> hi >> foo;
                        dist[lo-1][hi-1]=foo;
                        dist[hi-1][lo-1]=foo;
                }

                rep(i, 0, n) {
                        rep(j, 0, n) {
                                rep(k, 0, n) {
                                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                                }
                        }
                }

                rep(i, 0, fam) {
                        cin >> ini[i] >> fim[i];
                        ini[i]-=1;
                        fim[i]-=1;
                }

                int ans = solve(0, 0, 0);
                if (ans >= 1<<29) {
                        cout << -1 << "\n";
                } else {
                        cout << ans << "\n";
                }
        }
        return 0;
}

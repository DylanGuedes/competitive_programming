#include <bits/stdc++.h>

using namespace std;


#define rep(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define ins insert
#define popb pop_back
using ii = pair<int, int>;
using ll = long long;
int n;
ll dist[120][120];
vector<int> scc_size;
stack<int> s;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        int aux=0;

        rep(i, 0, n) {
                rep(j, 0, n) {
                        dist[i][j]=(ll)1<<40;
                }
        }


        rep(i, 0, n) {
                cin >> aux;
                dist[i][aux-1]=1;
        }

        ll best=(ll)1<<60;

        rep(k, 0, n) {
                rep(i, 0, n) {
                        rep(j, 0, n) {
                                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                        }
                }
        }

        ll ans=1;
        rep(i, 0, n) {
                best=(ll)1ll<<60;
                rep(j, 0, n) {
                        if (dist[i][j]==dist[j][i])
                                best=min(best, dist[i][j]);
                }
                ans = lcm(ans, best);
        }

        if (ans >= (ll)1<<30) {
                cout << -1 << "\n";
        } else {
                cout << ans << "\n";
        }

        return 0;
}


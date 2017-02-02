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
#define MAX 1000005
#define MYMOD (int)(1e9+7)
vector<int> g[MAX];
ll fact[MAX];

int main()
{
        ios::sync_with_stdio(false);

        fact[0]=1;
        fact[1]=1;
        for (int i=2; i<=MAX; ++i) {
                fact[i] = (fact[i-1]*i)%MYMOD;
        }

        cin >> n >> m;
        rep(i, 0, n) {
                int that, stub;
                cin >> that;
                rep(j, 0, that) {
                        cin >> stub;
                        g[stub-1].pb(i);
                }
        }

        sort(g, g+m);

        int accum=1;
        int total=1;
        rep(i, 1, m) {
                if (g[i]==g[i-1]) {
                        accum++;
                } else {
                        total = (total * fact[accum]) % MYMOD;
                        accum=1;
                }
        }
        total = (total * fact[accum])%MYMOD;

        cout << (total) << "\n";

        return 0;
}

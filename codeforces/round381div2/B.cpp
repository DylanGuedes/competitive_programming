#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

int mood[105];
int appear[105];

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        cin >> n >> m;
        rep(i, 0, n) {
                cin >> mood[i];
        }
        int origin, destination;
        ll ans = 0;
        rep(i, 0, m) {
                cin >> origin >> destination;
                if (origin > destination)
                        swap(origin, destination);
                origin-=1;
                destination-=1;
                ll total = 0;
                rep(i, origin, destination+1) {
                        total+=mood[i];
                }
                if (total > 0) {
                        rep(i, origin, destination+1) {
                                appear[i]++;
                        }
                }
        }
        rep(i, 0, n) {
                ans += mood[i]*appear[i];
        }
        cout << ans << "\n";
        return 0;
}

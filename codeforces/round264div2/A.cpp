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

int main()
{
        ios::sync_with_stdio(false);
        int n, s, x, y;
        cin >> n >> s;
        int mymin = -1<<30;
        bool ok = false;
        rep(i, 0, n) {
                cin >> x >> y;
                if (s>x || (s==x && y==0)) {
                        ok = true;
                        if (y!=0) {
                                mymin = max(mymin, 100-y);
                        } else {
                                mymin = max(mymin, 0);
                        }
                }
        }
        if (ok) {
                cout << mymin << "\n";
        } else {
                cout << -1 << "\n";
        }

        return 0;
}

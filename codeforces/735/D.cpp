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

        ll n; cin >> n;

        ll idx=min(n, (ll)sqrt(n)+10);
        bool prime=true;
        rep(i, 2, idx) {
                if (n%i == 0) {
                        prime=false;
                        break;
                }
        }

        if (prime) {
                cout << 1 << "\n";
        } else if (!(n&1)) {
                cout << 2 << "\n";
        } else {
                bool thatprime=true;
                idx=min(idx, n-2);
                rep(i, 2, idx) {
                        if ((n-2)%i ==0) {
                                thatprime=false;
                                break;
                        }
                }
                if (thatprime) {
                        cout << 2 << "\n";
                } else {
                        cout << 3 << "\n";
                }
        }

        return 0;
}

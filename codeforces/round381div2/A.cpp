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

int n;
int main()
{
        ios::sync_with_stdio(false);
        ll a, b, c;
        cin >> n >> a >> b >> c;
        if (n%4 == 0) {
                cout << 0 <<"\n";
        } else if (n%4 == 1) {
                cout << min(b+a, min(c, 3*a)) << "\n";
        } else if (n%4 == 2) {
                cout << min(min(b, 2*c), 2*a) << "\n";
        } else if (n%4==3) {
                cout << min(a,min(3*c, b+c)) << "\n";
        }
        return 0;
}

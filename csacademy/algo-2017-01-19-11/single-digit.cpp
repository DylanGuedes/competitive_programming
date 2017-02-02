#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define FOR(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m;
string str;

int main()
{
        ios::sync_with_stdio(false);

        int l, r;
        cin >> l >> r;

        set<int> myset;
        int total=0;
        rep(i, 1, 10) {
                total=1;
                for (int j=1; j<1000022;) {
                        myset.insert(i*total);
                        j*=10;
                        total+=j;
                }
        }

        int foo=0;
        for (auto it : myset) {
                if (it>=l && it<=r) {
                        // cout << it << "\n";
                        foo++;
                }
        }
        cout << foo << "\n";

        return 0;
}

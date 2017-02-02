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

set<int> myset;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int foo;
        rep(i, 0, n) {
                cin >> foo;
                myset.insert(foo);
        }
        cout << "top: " << *myset.rbegin() << "\n";
        return 0;
}

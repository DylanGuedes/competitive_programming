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

int n, m, foo, aux;
string str;

int main()
{
        ios::sync_with_stdio(false);
        int z;
        cin >> n >> m >> z;
        set<int> myset;
        for(int i=n; i<=z; i+=n) {
                myset.insert(i);
        }
        set<int> other;
        for(int i=m; i<=z; i+=m) {
                other.insert(i);
        }
        int total=0;
        for (auto it : other) {
                if (myset.count(it)>0) {
                        total++;
                }
        }
        cout << total << "\n";
        return 0;
}

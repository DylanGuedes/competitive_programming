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
        set<int> extra;
        extra.insert(1);
        extra.insert(3);
        extra.insert(5);
        extra.insert(7);
        extra.insert(8);
        extra.insert(10);
        extra.insert(12);

        cin >> m >> n;
        if (extra.count(m) > 0) {
                if (n<=5) {
                        cout << 5 << "\n";
                } else {
                        cout << 6 << "\n";
                }
        } else if (m==2) {
                if (n==1) {
                        cout << 4 << "\n";
                } else {
                        cout << 5 << "\n";
                }
        } else {
                if (n<=6) {
                        cout << 5 << "\n";
                } else {
                        cout << 6 << "\n";
                }
        }
        return 0;
}

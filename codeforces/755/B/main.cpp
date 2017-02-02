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
string str;
set<string> poland, other;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        rep(i, 0, n) {
                cin >> str;
                poland.insert(str);
        }

        rep(i, 0, m) {
                cin >> str;
                other.insert(str);
        }

        int total=0;
        bool flag=false;
        for (auto it : poland) {
                if (other.count(it)>0) {
                        total++;
                        flag=!flag;
                }
        }

        if (total == 0) {
                if (poland.size() > other.size()) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }
        } else {
                if (total&1) {
                        if (poland.size()+1 > other.size()) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                } else {
                        if (poland.size() > other.size()) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                }
        }

        return 0;
}

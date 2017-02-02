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

int n;
string str;

int main()
{
        ios::sync_with_stdio(false);
        cin >> str;

        int len=str.size();
        rep(i, 0, len) {
                str.push_back(str[i]);
        }

        set<string> myset;
        rep(i, 0, len) {
                string a="";
                rep(j, 0, len) {
                        a.pb(str[i+j]);
                }
                myset.insert(a);
        }
        cout << myset.size() << "\n";

        return 0;
}

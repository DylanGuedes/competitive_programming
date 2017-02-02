#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>k;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> myv;
set<int> myset;
map<char, int> mymap;
int n, t, s;
int a[200005];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        repi(i, 0, n)
                cin >> a[i];
        bool possible = true;
        if (n > 1) {
                repi(i, 1, n) {
                        if (a[i-1] == 0 && !(a[i]&1) && a[i] != 0) {
                                possible = false;
                        }
                }
        } else {
                a[0]==2 ? possible = true : possible = false;
        }

        possible ? cout << "YES\n" : cout << "NO\n";
        return 0;
}

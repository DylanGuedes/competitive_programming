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

int n;
string str;
int dep[32];
set<ii> myset;

void solve(int x, int y, int idx, int many, bool vert)
{
        myset.insert(ii(x, y));
        if (vert) {
                if (many<=dep[idx]) {
                        if (y>0) {
                                solve(x, y+1, idx, many+1, vert);
                        } else {
                                solve(x, y-1, idx, many+1, vert);
                        }
                } else {
                        if (n<idx) {
                                if (vert) {
                                        if (y>0) {
                                                solve(x+1, y+1, idx+1, 2, false);
                                                solve(x-1, y+1, idx+1, 2, false);
                                        } else {
                                                solve(x+1, y-1, idx+1, 2, false);
                                                solve(x-1, y-1, idx+1, 2, false);
                                        }
                                }
                        }
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n) {
                cin >> dep[i];
        }
        solve(0, 0, 0, 1, true);
        cout << myset.size() << "\n";
        return 0;
}

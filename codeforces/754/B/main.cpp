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
char grid[5][5];

int main()
{
        ios::sync_with_stdio(false);

        rep(i, 0, 4) {
                rep(j, 0, 4) {
                        cin >> grid[i][j];
                }
        }

        rep(i, 0, 4) {
                rep(j, 0, 4) {
                        vector<vector<ii> > ans;
                        vector<ii> right {ii(j+1, i), ii(j+2, i)};
                        vector<ii> left { ii(j-1, i), ii(j-2, i)};
                        vector<ii> bottom { ii(j, i+1), ii(j, i+2)};
                        vector<ii> top { ii(j, i-1), ii(j, i-2)};
                        vector<ii> firstquad {ii(j+1, i+1), ii(j+2, i+2)};
                        vector<ii> secondquad {ii(j-1, i+1), ii(j-2, i+2)};
                        vector<ii> thirdquad {ii(j-1, i-1), ii(j-2, i-2)};
                        vector<ii> quadquad {ii(j+1, i-1), ii(j+2, i-2)};

                        ans.pb(right);
                        ans.pb(left);
                        ans.pb(top);
                        ans.pb(bottom);
                        ans.pb(firstquad);
                        ans.pb(secondquad);
                        ans.pb(thirdquad);
                        ans.pb(quadquad);

                        int count=0;
                        for (auto dir : ans) {
                                count++;
                                bool ok=true;
                                bool one=false;
                                if (grid[i][j]=='o') {
                                        ok=false;
                                        break;
                                } else if (grid[i][j]=='.') {
                                        one=true;
                                }
                                bool backup=one;
                                for (auto it : dir) {
                                        if (it.first < 0 || it.second <0 || it.first > 3 || it.second > 3) {
                                                ok=false;
                                                break;
                                        }
                                        if (grid[it.second][it.first]=='o') {
                                                ok=false;
                                                break;
                                        }
                                        if (grid[it.second][it.first]=='.') {
                                                if (one==true) {
                                                        ok=false;
                                                        break;
                                                }
                                                one=true;
                                        } else if (grid[it.second][it.first]!='x') {
                                                ok=false;
                                                break;
                                        }
                                }
                                if (ok==true) {
                                        cout << "YES\n";
                                        return 0;
                                }
                        }

                }
        }
        cout << "NO\n";

        return 0;
}

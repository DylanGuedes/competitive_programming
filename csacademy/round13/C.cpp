#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define rep(i, j, k)for(int i=j;i<k;++i)
#define DEBUG(arg, x) cout << arg << " => " << x << "\n"

using ii = pair<int, int>;
using ll = long long;
int t, n;
pair<int, int> a1[50005];
pair<int, int> a2[50005];

bool myfunc(ii a, ii b)
{
        return a.first < b.first;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> t;
        while (t--) {
                cin >> n;
                rep(i, 0, n) {
                        cin >> a1[i].first;
                        a1[i].second=i+1;
                }

                rep(i, 0, n) {
                        cin >> a2[i].first;
                        a2[i].second=i+1;
                }

                sort(a1, a1+n, less<ii>());
                sort(a2, a2+n, greater<ii>());
                vector<ii> myv;

                bool ok=true;
                rep(i, 0, n) {
                        myv.pb(ii(a1[i].second, a2[i].second));
                        if (a1[i].first==a2[i].first) {
                                ok=false;
                                break;
                        }
                }
                sort(myv.begin(), myv.end(), myfunc);
                // cout << "MYSET:\n";
                // for (auto it  :myv) {
                //         cout << it.first << " " << it.second << "\n";
                // }
                if (ok) {
                        for (auto it : myv) {
                                if (it!=*myv.begin())
                                        cout << " ";
                                cout << it.second;
                        }
                } else {
                        cout << -1;
                }
                cout << "\n";
        }
        return 0;
}

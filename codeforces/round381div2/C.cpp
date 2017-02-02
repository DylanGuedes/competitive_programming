#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

int myarr[100010];
vector<ii> queries;

bool myfunc(ii a, ii b)
{
        return a.second-a.first < b.second-b.first;
}

int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        cin >> n >> m;
        int myleft, myright;
        int minquery=1<<30;
        int thatidx = -1;
        rep(i, 0, m) {
                cin >> myleft >> myright;
                if (myright-myleft < minquery) {
                        minquery = myright-myleft;
                        thatidx = i;
                }
                queries.eb(myleft, myright);
        }
        memset(myarr, -1, sizeof myarr);
        cout << minquery+1 << "\n";
        int idx=0;
        rep(i, 0, n) {
                if (i)
                        cout << " ";
                cout << idx;
                idx=(idx+1)%(minquery+1);
        }
        cout << "\n";
        return 0;
}

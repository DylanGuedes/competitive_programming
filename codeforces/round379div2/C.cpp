#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<ll, ll>;
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
#define mt make_tuple
double const eps = 1e-10;
double const pi = acos(-1);

vector<ii> spell1;
vector<ii> spell2;
ll n, m, k, x, s;

ll bsearch(ll idx)
{
        ll act_mana=spell1[idx].first;
        ll lo=0;
        ll hi=k-1;
        ll mid;
        ll ans=0;
        while(hi>=lo) {
                mid=(hi+lo)/2;
                if (spell2[mid].first+act_mana>s) {
                        hi=mid-1;
                } else {
                        lo=mid+1;
                        ans=mid;
                }
        }
        if (act_mana+spell2[ans].first>s)
                return spell1[idx].second*n;
        return spell1[idx].second*(n-spell2[ans].second);
}

int main()
{
        ios::sync_with_stdio(false);

        cin >> n >> m >> k;
        cin >> x >> s;

        spell1.resize(m);
        spell2.resize(k);

        rep(i, 0, m) cin >> spell1[i].second;
        rep(i, 0, m) cin >> spell1[i].first;
        rep(i, 0, k) cin >> spell2[i].second;
        rep(i, 0, k) cin >> spell2[i].first;

        ll ans=x*n;
        rep(i, 0, m) {
                if (spell1[i].first<=s)
                        ans=min(ans, bsearch(i));
        }
        rep(i, 0, k) {
                if (spell2[i].first<=s)
                        ans=min(ans, (ll)x*(n-spell2[i].second));
        }

        cout << ans << "\n";
        return 0;
}

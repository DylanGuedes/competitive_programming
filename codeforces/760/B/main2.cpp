#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(ll i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m, foo, aux;
int k;
string str;

bool correct(ll idx)
{
        ll current=idx;

        ll aux = min((ll)k-1, idx);
        current+=(aux*(aux-1))/2;
        current+=(idx-aux)*(k-1);

        aux = min((ll)n-k, idx);
        current+=(aux*(aux-1))/2;
        current+=(idx-aux)*(n-k);

        return current<=m;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m >> k;

        ll lo=1;
        ll hi=m;
        ll mi=1;

        m-=n;

        ll ans=0;
        while(hi>=lo) {
                mi=lo+(hi-lo)/2;
                if (correct(mi)) {
                        ans=max(ans, mi);
                        lo=mi+1;
                } else {
                        hi=mi-1;
                }
        }

        cout << ans+1 << "\n";

        return 0;
}

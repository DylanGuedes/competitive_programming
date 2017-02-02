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

#define MAX 100010
int n, m, k;
struct operation {
        int l, r, d;
};

operation op[MAX];
int appear[MAX];
ll accum[MAX];
ll arr[MAX];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m >> k;
        rep(i, 0, n) {
                cin >> arr[i];
        }
        rep(i, 0, m) {
                cin >> op[i].l >> op[i].r >> op[i].d;
                op[i].l-=1;
        }
        int lo, hi;
        rep(i, 0, k) {
                cin >> lo >> hi;
                lo--;
                appear[lo]++;
                appear[hi]--;
        }
        ll idx=0;
        rep(i, 0, m) {
                idx+=appear[i];
                accum[op[i].l]+=(op[i].d*idx);
                accum[op[i].r]-=(op[i].d*idx);
        }

        rep(i, 1, n) {
                accum[i]+=accum[i-1];
        }
        rep(i, 0, n) {
                cout << arr[i]+accum[i] << " ";
        }
        cout << "\n";
        return 0;
}

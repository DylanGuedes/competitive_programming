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
char ch[110];
int arr[110];
int appear[200];

int solve(int idx, int aggr)
{
        if (idx<0)
                return 0;
        ll here=pow(2,aggr)*arr[idx];
        appear[here]=1;

        ll val=here+solve(idx-1, aggr+1);
        appear[val]=1;
        if (val>n+1) {
                return arr[idx];
        } else {
                return val;
        }
}


int main()
{
        ios::sync_with_stdio(false);

        memset(appear, 0, sizeof appear);
        cin >> n;
        rep(i, 0, n) {
                cin >> ch[i];
                if (ch[i]=='1') {
                        arr[i]=1;
                } else {
                        arr[i]=0;
                }

        }

        solve(n-1, 0);

        ll ans=0;
        rep(i, 2, n+2) {
                ll v=1;
                while (appear[v] && v<i) {
                        v++;
                }
                ans+=v;
        }

        cout << ans << "\n";

        return 0;
}

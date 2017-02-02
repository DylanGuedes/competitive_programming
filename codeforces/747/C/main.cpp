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

int n, q, t, k, d;
string str;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> q;
        priority_queue<int, vector<int>, greater<int> > ok_servers;
        priority_queue<ii, vector<ii>, greater<ii> > busy_servers;
        rep(i, 1, n+1) {
                ok_servers.emplace(i);
        }
        rep(i, 0, q) {
                cin >> t >> k >> d;
                while (not busy_servers.empty() && busy_servers.top().first<=t) {
                        ok_servers.emplace(busy_servers.top().second);

                        busy_servers.pop();
                }
                if (ok_servers.size()>=k) {
                        int sum=0;
                        rep(j, 0, k) {
                                busy_servers.emplace(t+d, ok_servers.top());
                                sum+=(ok_servers.top());
                                ok_servers.pop();
                        }
                        cout << sum << "\n";
                } else {
                        cout << -1 << "\n";
                }
        }

        return 0;
}

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

int main()
{
        ios::sync_with_stdio(false);
        int s, x1, x2;
        cin >> s >> x1 >> x2;
        int t1, t2;
        cin >> t1 >> t2;
        int p, d;
        cin >> p >> d;
        if (t1>t2) {
                cout << (max(x1, x2)-min(x1, x2))*t2 << "\n";
        } else {
                if (x1<x2) {
                        if (d==1) {
                                if (p<=x1) {
                                        if (t1<t2) {

                                        }
                                }
                        }
                }
        }

        return 0;
}

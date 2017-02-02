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

int n, m;
int alex[100005];
int ben[100005];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        rep(i, 0, n)
                cin >> alex[i];
        rep(i, 0, m)
                cin >> ben[i];
        sort(alex, alex+n);
        sort(ben, ben+m);
        int ptr=0;
        int cp=0;
        int won=0;
        rep(i, 0, m) {
                while (ben[i]>=alex[ptr] && ptr<n) {
                        cp+=alex[ptr];
                        ptr++;
                }
                if (ptr>=n)
                        break;
                won++;
                ptr++;
        }
        if (won>=m) {
                rep(i, ptr, n) {
                        cp+=alex[i];
                }
                cout << cp << "\n";
        } else {
                cout << -1 << "\n";
        }
        return 0;
}

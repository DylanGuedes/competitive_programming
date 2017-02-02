#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define ins insert
#define popb pop_back
using ii = pair<int, int>;
using ll = long long;
ll n;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        vector<int> ans {8, 4, 2, 6};
        if (n == 0) {
                cout << 1 << "\n";
                return 0;
        }
        if ((n%4)-1<0) {
                cout << ans[3] << "\n";
        } else {
                cout << ans[(n%4)-1] << "\n";
        }
        return 0;
}


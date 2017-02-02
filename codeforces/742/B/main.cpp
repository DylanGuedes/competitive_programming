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
ll arr[1000100];
ll appear[1000100];

int main()
{
        ios::sync_with_stdio(false);
        ll x;
        cin >> n >> x;
        memset(appear, 0, sizeof appear);
        ll total=0;
        rep(i, 0, n) {
                cin >> arr[i];
                total+= (appear[arr[i] ^ x]);
                appear[arr[i]]+=1;
        }
        cout << total << "\n";
        return 0;
}


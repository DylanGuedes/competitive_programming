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
int n;
int arr[100010];

int main()
{
        ios::sync_with_stdio(false);
        int x;
        cin >> n >> x;
        rep(i, 0, n) {
                cin >> arr[i];
        }
        ll total=0;

        rep(i, 0, n) {
                rep(j, i+1, n) {
                        total += (arr[i] xor arr[j]) == x;
                }
        }
        cout << total << "\n";
        return 0;
}

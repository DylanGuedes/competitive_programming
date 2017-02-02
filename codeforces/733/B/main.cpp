#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define FOR(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m;
string str;
#define MAX 100010
ii arr[MAX];

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;

        int total_l=0, total_r=0;

        rep(i, 0, n) {
                cin >> arr[i].first >> arr[i].second;
                total_l+=arr[i].first;
                total_r+=arr[i].second;
        }

        int ans=abs(total_l-total_r);
        int start=ans;
        int idx=-1;
        rep(i, 0, n) {
                total_l-=arr[i].first;
                total_l+=arr[i].second;

                total_r+=arr[i].first;
                total_r-=arr[i].second;

                if (abs(total_l-total_r) > ans) {
                        idx=i;
                        ans=abs(total_l-total_r);
                }

                total_r+=arr[i].second;
                total_r-=arr[i].first;
                total_l+=arr[i].first;
                total_l-=arr[i].second;
        }

        if (ans==start) {
                cout << 0 << "\n";
        } else {
                cout << idx+1 << "\n";
        }

        return 0;
}

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
#define MAX 100005
int arr[MAX];
int used[MAX];

ll gcd(ll a, ll b)
{
        if (b==0) {
                return a;
        } else {
                return gcd(b, a%b);
        }
}

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;
        ll par=0, impar=0;
        ll currentgcd=0;
        rep(i, 0, n) {
                cin >> arr[i];
                for (auto it : myset) {
                        if (gcd(
                }
        }

        ll ans=par;
        sort(arr, arr+n);
        rep(i, 0, n) {
                if (used[arr[i]]) {
                        continue;
                }
                if (arr[i]&1) {
                        used[arr[i]]=true;
                        currentgcd=arr[i];
                        ll ele=1;
                        rep(j, i+1, n) {
                                if (gcd(currentgcd, arr[j])!=1) {
                                        currentgcd=gcd(currentgcd, arr[j]);
                                        ele++;
                                        // debug(arr[j]);
                                        used[arr[j]]=true;
                                }
                        }
                        // debug(ele);
                        ans=max(ans, ele);
                        if (i>(n-par) || ans>n/2) {
                                break;
                        }
                }
        }
        cout << ans << "\n";


        return 0;
}

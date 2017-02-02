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

int n, m, foo, aux;
string str;
int arr[105];
int arr2[105];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;

        rep(i, 0, n) {
                cin >> arr[i];
        }

        rep(i, 0, n) {
                cin >> arr2[i];
        }

        int diff = arr[0]-arr2[0];

        bool nope=true;
        rep(i, 1, n) {
                if (arr[i]+diff != arr2[i]) {
                        nope=false;
                        break;
                }
        }

        bool nope2=true;
        rep(i, 1, n) {
                if (arr[i]-diff != arr2[i]) {
                        nope2=false;
                        break;
                }
        }

        if (!nope && !nope2) {
                cout << "NO\n";
        } else {
                cout << "YES\n";
        }


        return 0;
}

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

vector<int> arr;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n) {
                cin >> aux;
                arr.pb(aux);
        }


        for (int i=0; i <n/2; i+=2) {
                aux = arr[i];
                arr[i] = arr[n-1-i];
                arr[n-1-i] = aux;
        }

        for (auto it : arr) {
                cout << it << " ";
        }
        cout << "\n";
        return 0;
}

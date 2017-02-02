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

#define MAX 1010
int appear[MAX];
int main()
{
        ios::sync_with_stdio(false);
        int a, b;
        cin >> a >> b;

        rep(i, 2, MAX) {
                for(int j=i; j<=MAX; j+=i) {
                        appear[j]++;
                }
        }

        int total=0;
        rep(i, a, b+1) {
                if (!(appear[i]&1)) {
                        total++;
                }
        }

        cout << total << "\n";

        return 0;
}

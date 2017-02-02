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
int appear[MAX];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        int aux;
        rep(i, 0, n) {
                cin >> aux;
                appear[aux]++;
        }

        int limit = 100000;
        int total=1;
        for (int i=2; i<=limit; i++) {
                int here=0;
                for (int j=i; j<=limit; j+=i) {
                        here += appear[j];
                }
                total = max(total, here);
        }

        cout << total << "\n";

        return 0;
}

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

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        int aux=240;
        aux-=m;
        int total=0;
        rep(i, 1, n+1) {
                if (i*5<=aux) {
                        total++;
                        aux-=i*5;
                }
        }
        cout << total << "\n";

        return 0;
}
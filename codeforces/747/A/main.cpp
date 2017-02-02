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

int n;
string str;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int a=0;
        int mindiff=1<<30;
        ii resp;
        rep(b, 1, 1000000) {
                a = n/b;
                if (a>b)
                        continue;
                if (a*b != n)
                        continue;
                if (b-a < mindiff) {
                        resp.first=a;
                        resp.second=b;
                        mindiff=b-a;
                }
        }
        cout << resp.first << " " << resp.second << "\n";
        return 0;
}

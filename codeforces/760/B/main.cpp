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
int k;
string str;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m >> k;
        int diff = m-n;
        if (n==1) {
                cout << m << "\n";
        } else if (n==2) {
                if (m&1) {
                        cout << (m/2)+1 << "\n";
                } else {
                        cout << (m/2) << "\n";
                }
        } else {
                if (not(k==1 || k==n)) {
                        ll lo=1;
                        ll hi=1000000000;
                        ll mi=0;
                        while(hi>=lo) {
                                mi=(hi+lo)/2;
                                if (mi*(mi+1) < m) {
                                        lo=mi+1;
                                } else if (mi*(mi+1) > m) {
                                        hi=mi-1;
                                } else if (mi*(mi+1)==m) {
                                        break;
                                }
                        }
                        cout << mi << "\n";
                } else {
                        ll lo=1;
                        ll hi=1000000000;
                        ll mi=0;
                        while(hi>=lo) {
                                mi=(hi+lo)/2;
                                if (mi*(mi+1) == 2*m) {
                                        break;
                                } else if (mi*(mi+1) < (2*m)) {
                                        lo=mi+1;
                                } else if (mi*(mi+1) > (2*m)) {
                                        hi=mi-1;
                                }
                        }
                        cout << mi << "\n";
                }
        }
        return 0;
}

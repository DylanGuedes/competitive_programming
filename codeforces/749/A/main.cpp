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
        set<int> myset;
        if (n%2 == 0) {
                int mult = n/2;
                cout << mult << "\n";
                rep(i, 0, mult) {
                        cout << 2 << " ";
                }
                cout << "\n";
        } else {
                if (n==3) {
                        cout << 1 << "\n";
                        cout << 3 << "\n";
                } else {
                        int mult = n-3;
                        mult/=2;
                        cout << mult+1 << "\n";
                        rep(i, 0, mult) {
                                cout << 2 << " ";
                        }
                        cout << 3 << "\n";
                }
        }
        return 0;
}

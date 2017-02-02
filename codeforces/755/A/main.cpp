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

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;

        int that = 31632;
        vector<bool> is_prime(32000, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (int i=3; i<=that; i+=2) {
                if (is_prime[i] == true) {
                        int thatidx = that/i;
                        FOR(j, i, thatidx+1) {
                                is_prime[i*j] = false;
                        }
                }
        }

        if (n>=3) {
                if (n&1) {
                        cout << 1 << "\n";
                } else {
                        rep(i, 1, 100001) {
                                if (is_prime[n*i+1]==false) {
                                        cout << i << "\n";
                                        return 0;
                                }
                        }
                }
        } else {
                if (n == 1) {
                        cout << 3 << "\n";
                } else {
                        cout << 4 << "\n";
                }
        }

        return 0;
}

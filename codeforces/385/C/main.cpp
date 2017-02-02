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
#define MAX 10000010
int appear[MAX];
ll primes[MAX];
int pre[MAX];
bool is_prime[MAX];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int foo;
        rep(i, 0, n) {
                cin >> foo;
                appear[foo]++;
        }

        int that = MAX;
        memset(is_prime, true, sizeof is_prime);
        is_prime[0] = false;
        is_prime[1] = false;

        int lo=0;
        for (int i=2; i<=that; i++) {
                primes[i]=primes[i-1];
                if (is_prime[i]==false)
                        continue;

                int divs=appear[i];
                for (int j=i*2; j<=that; j+=i) {
                        is_prime[j]=false;
                        divs+=appear[j];
                }
                primes[i]+=divs;
        }

        // cout << "PRIMES:\n";
        // rep(i, 0, 10) {
        //         cout << primes[i] << "\n";
        // }

        cin >> m;
        int l, r;
        while(m--) {
                cin >> l >> r;
                r=min(r, MAX);
                l=min(l, MAX);
                cout << primes[r]-primes[l-1] << "\n";
        }
        return 0;
}

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
int arr[MAX];
ll appear[MAX];

int main()
{
        ios::sync_with_stdio(false);

        cin >> n;
        ll par=0, impar=0;
        ll currentgcd=0;

        rep(i, 0, n) {
                cin >> arr[i];
                for (int j=(arr[i]/2); j>=2; j--) {
                        if (arr[i]%j == 0) {
                                appear[j]++;
                        }
                }
        }

        sort(appear, appear+n);
        cout << appear[n-1] << "\n";


        return 0;
}

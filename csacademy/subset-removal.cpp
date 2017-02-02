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

int n, k;
string str;

#define MAX 1010
int arr[MAX];
multiset<int> myset;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> k;
        int aux;
        rep(i, 0, n) {
                cin >> aux;
                myset.insert(aux);
                if (myset.count(aux)==k) {
                        myset.erase(aux);
                }
        }

        int total=-1<<30;
        for (auto it : myset) {
                total = max(total, (int)myset.count(it));
        }

        cout << max(total, 0) << "\n";
        return 0;
}

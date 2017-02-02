#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
double const eps = 1e-10;
double const pi = acos(-1);

int arr[1010];

int main()
{
        ios::sync_with_stdio(false);

        int n;
        cin >> n;

        string mys;
        cin >> mys;
        ll anton=0;
        ll danik=0;
        for (auto it : mys) {
                if (it == 'A') {
                        anton++;
                } else {
                        danik++;
                }
        }

        if (anton>danik) {
                cout << "Anton\n";
        } else if (danik>anton) {
                cout << "Danik\n";
        } else {
                cout << "Friendship\n";
        }

        return 0;
}

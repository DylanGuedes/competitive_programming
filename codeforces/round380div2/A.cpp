#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define ins insert

bool arr[105];
bool filler[105];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        string mys;
        cin >> n;
        cin >> mys;
        memset(arr, 0, sizeof arr);
        memset(filler, 0, sizeof filler);
        rep(i, 0, n) {
                if (i>=2 && mys[i-2]=='o' && mys[i-1]=='g' && mys[i]=='o') {
                        mys[i]='?';
                        mys[i-1]='?';
                        mys[i-2]='?';
                } else if (i>1 && mys[i]=='o' && mys[i-1]=='g' && (mys[i-2]=='?' || mys[i-2]=='!')) {
                        mys[i]='!';
                        mys[i-1]='!';
                }
        }

        rep(i, 0, n) {
                if (mys[i]=='?') {
                        cout << "***";
                        i+=2;
                } else if (mys[i]!='!') {
                        cout << mys[i];
                }
        }
        cout << "\n";
        return 0;
}

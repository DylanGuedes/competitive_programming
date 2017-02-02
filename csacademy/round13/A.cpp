#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define emp emplace
#define ins insert
#define rep(i, j, k)for(int i=j;i<k;++i)
#define DEBUG(arg, x) cout << arg << " => " << x << "\n"

using ii = pair<int, int>;
using ll = long long;

struct point {
        int x, y, idx;
};

point arr[1005];

bool myfunc(point a, point b)
{
        if (a.x==b.x) {
                return a.y>b.y;
        } else {
                return a.x>b.x;
        }
}

int n;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;

        rep(i, 0, n) {
                cin >> arr[i].x >> arr[i].y;
                arr[i].idx=i+1;
        }

        sort(arr, arr+n, myfunc);
        if (arr[0].x>arr[1].x && arr[0].y>arr[1].y)
                cout << arr[0].idx << "\n";
        else
                cout << -1 << "\n";
        return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int arr[100010];

int n, k;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> k;
        rep(i, 0, n) {
                cin >> arr[i];
        }
        sort(arr, arr+n);
        return 0;
}

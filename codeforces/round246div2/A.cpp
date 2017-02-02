#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int arr[2020];

int main()
{
        ios::sync_with_stdio(false);
        int n, k;
        cin >> n >> k;
        rep(i, 0, n)
                cin >> arr[i];

        sort(arr, arr+n);
        int val=n/3;

        int total=0;
        rep(i, 0, val) {
                if (5-arr[3*i+0]>=k && 5-arr[3*i+1]>=k && 5-arr[3*i+2]>=k) {
                        total++;
                } else {
                        break;
                }
        }
        cout << total << "\n";

        return 0;
}

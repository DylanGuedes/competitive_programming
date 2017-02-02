#include <bits/stdc++.h>

using namespace std;
#define rep(i, j, k)for(int i=j;i<k;++i)
using ll=long long;

int main()
{
        ios::sync_with_stdio(false);
        ll arr[3];
        rep(i, 0, 3)
                cin >> arr[i];
        ll total=0;
        while ((arr[0]+arr[1]+arr[2])>2) {
                sort(arr, arr+3);
                arr[0]-=2;
                arr[2]-=1;
                total++;
        }
        if (arr[0]==1 && arr[1]==1 && arr[2]==1) {
                total++;
        }
        cout << total << "\n";
        return 0;
}

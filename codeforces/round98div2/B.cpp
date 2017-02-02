#include <bits/stdc++.h>

using namespace std;
#define rep(i, j,k )for(int i=j;i<k;++i)

int arr[6000];
set<int> not_used;

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        memset(arr,0, sizeof arr);

        int idx;
        rep(i, 0, n) {
                cin >> idx;
                arr[idx]+=1;
        }
        int cnt=0;
        int reserva=0;
        rep(i,1, 5002) {
                if (i>=1 && i<=n && arr[i]>1) {
                        reserva+=arr[i]-1;
                } else if (i>=1 && i<=n && arr[i]<1) {
                        reserva--;
                        cnt++;
                } else if (i>n && arr[i]>0) {
                        reserva+=(arr[i]);
                }
        }

        cout << cnt << "\n";
        return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[110];
#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        int aux;
        rep(i, 0, n) {
                cin >> aux;
                arr[aux-1]=i;
        }
        rep(i, 0, n) {
                if (i)
                        cout << " ";
                cout << arr[i]+1;
        }
        cout << "\n";
        return 0;
}

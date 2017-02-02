#include <bits/stdc++.h>

using namespace std;
#define rep(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        int num[2];
        num[0]=0;num[1]=0;
        int aux;
        rep(i, 0, n) {
                cin >> aux;
                num[aux]++;
        }
        if (n==1) {
                if (num[1])
                        cout << "YES\n";
                else
                        cout << "NO\n";
        } else {
                if (num[0]==1)
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }
        return 0;
}

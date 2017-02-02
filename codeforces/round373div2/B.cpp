#include <bits/stdc++.h>

using namespace std;
int n;
#define repi(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        string mystr;
        cin >> mystr;

        char k[] = {'r','b'};
        int v[] = {0, 0};
        int that = 1;
        repi(i, 0, n) {
                if (mystr[i] != k[that]) {
                        v[that]++;
                }
                that = 1-that;
        }
        int diff = min(v[0], v[1]);
        int ans1 = diff+abs(v[0]-v[1]);

        that = 0;
        v[0] = 0;
        v[1] = 0;
        repi(i, 0, n) {
                if (mystr[i] != k[that]) {
                        v[that]++;
                }
                that = 1-that;
        }
        diff = min(v[0], v[1]);
        int ans2 = diff+abs(v[0]-v[1]);;
        cout << min(ans1, ans2) << "\n";
        return 0;
}

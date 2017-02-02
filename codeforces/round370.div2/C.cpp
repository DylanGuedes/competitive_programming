#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
ll y;

int solve(int a, int b, int c)
{
        if (a==y && b==y && c==y)
                return 0;
        if (a+b <= c || a+c <= b || c+b <= a || a<y || b<y || c<y)
                return 1<<30;
        int ans = 0xffffff;
        if (a!=y) {
                ans = min(ans, solve(y, b, c)+1);
                if (2*y-1 < a) {
                        ans = min(ans, solve(y*2-1, b, c)+1);
                }

                if (a > abs(b-c)+1) {
                        ans = min(ans, solve(abs(b-c)+1, b, c)+1);
                }

        }
        if (b!=y) {
                ans = min(ans, solve(a, y, c)+1);
                if (b > 2*y-1)
                        ans = min(ans, solve(a, y*2-1, c)+1);
                if (b > abs(a-c)+1)
                        ans = min(ans, solve(a, abs(a-c)+1, c)+1);
        }
        if (c!=y) {
                ans = min(ans, solve(a, b, y)+1);
                if (c > y*2-1)
                        ans = min(ans, solve(a, b, y*2-1)+1);
                if (c > abs(b-c)+1)
                        ans = min(ans, solve(a, b, abs(b-c)+1)+1);
        }
        return ans;
}

int main()
{
        ll x;
        cin >> x >> y;
        ll items[3];
        cout << solve(x, x, x) << "\n";
        return 0;
}

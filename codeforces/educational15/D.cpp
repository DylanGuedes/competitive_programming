#include <iostream>

using namespace std;

long long int d, k, a, b, t;

long long int solve(long long int idx, long long int remaining)
{
    printf("idx: %d\n", idx);
    if (idx == d)
        return 0;

    long long int ans = solve(idx+1, remaining)+b;
    if (remaining > 0) {
        ans = min(ans, solve(idx+1, remaining-1)+a);
    } else {
        ans = min(ans, solve(idx, k)+t);
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> d >> k >> a >> b >> t;
    cout << solve(0, k) << "\n";
    return 0;
}

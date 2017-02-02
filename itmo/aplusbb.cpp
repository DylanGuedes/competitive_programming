#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream cin("aplusbb.in");
std::ofstream cout("aplusbb.out");
#else
using std::cin;
using std::cout;
#endif

using ll = long long;

int main() {
        ll a, b;
        cin >> a >> b;
        cout << (a + (b*b)) << "\n";
        return 0;
}

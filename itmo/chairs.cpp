#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("chairs.in");
std::ofstream fout("chairs.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;

int main() {
        int s[3];
        rep(i, 0, 3)
                fin >> s[i];

        double total=0;

        rep(i, 0, 3) {
                total += (double)s[i]/2.0;
        }
        fout << fixed << setprecision(6) << total/3 << "\n";
        return 0;
}

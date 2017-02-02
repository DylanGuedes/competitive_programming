#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("prepare.in");
std::ofstream fout("prepare.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

int p[110];
int t[110];
using ll = long long;

int main() {
        int n;
        fin >> n;
        rep(i, 0, n) {
                fin >> p[i];
        }
        rep(i, 0, n) {
                fin >> t[i];
        }

        ll total=0;
        bool has_p=false, has_t=false;

        rep(i, 0, n) {
                if (p[i]>t[i]) {
                        has_p=true;
                        total+=p[i];
                } else {
                        has_t=true;
                        total+=t[i];
                }
        }

        if (has_p && has_t) {
                fout << total << "\n";
        } else {
                ll lowest_diff = 1<<30;
                int idx=-1;
                rep(i, 0, n) {
                        if (lowest_diff > abs(p[i]-t[i])) {
                                lowest_diff = abs(p[i]-t[i]);
                                idx=i;
                        }
                }

                total -= max(p[idx], t[idx]);
                total += min(p[idx], t[idx]);
                fout << total << "\n";
        }
        return 0;
}

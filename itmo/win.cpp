#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("win.in");
std::ofstream fout("win.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
long double arr[20];

int main() {
        int n;
        int aux;
        fin >> n;
        rep(i, 0, n) {
                fin >> aux;
                arr[i]=(double)aux/60.0;
        }
        sort(arr, arr+n);
        long double total=0;
        int ans=0;
        rep(i, 0, n) {
                if (arr[i]+total <= 300.0) {
                        total+=arr[i];
                        ans++;
                } else {
                        break;
                }
        }
        fout << ans << "\n";
        return 0;
}

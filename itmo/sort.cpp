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

ll merge(int left, int right)
{
        if (left==right)
                return 0;
        if (left+1==right)
                return 0;
        int mid = (left+right)/2;
        merge(left, mid);
        merge(mid, right);

        int i=left, j=mid, k=right;
        while (i<mid || j<right) {
                if (j==right || (i<mid && a[i]<=a[j])) {
                        w[right] = a[i];
                        i++;
                        right++;
                } else {
                        w[right]=a[j];
                        ++j;
                        right++;
                }
        }
        rep(i, left, right)
                a[i]=w[i];
}

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

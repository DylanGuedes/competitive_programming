#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ep emplace_back
using ll = long long;
using ii = pair<int, int>;
#define all(x) x.begin(),x.end()
#define repd(i, j, k)for(int i=j;i>=k;i--)
double const pi = acos(-1.0);
double const eps = 1e-10;
int const oo = 1<<30;

double equals(double a, double b)
{
        return fabs(a-b)<eps;
}

int myfloor(double val)
{
        if (val-(int)val > eps) {
                return 1+(int)val;
        } else {
                return (int)val;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        int w, h;
        rep(z, 0, t) {
                cin >> w >> h;
                cout << "Caso " << z+1 << ": ";
                if (w==1 && h==1) {
                        cout << "1\n";
                } else {
                        int p1=round((double)(w-h)/2);
                        int p2=2*min(1, (int)ceil((double)w/h)-1);
                        cout << "p1: " << p1 << ", p2: " << p2 << "\n";
                        cout << p1+p2+1 << "\n";
                }
        }
        return 0;
}

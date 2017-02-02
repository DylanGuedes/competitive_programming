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

class pt {
public:
        double x, y;
        pt(double _a, double _b):x(_a),y(_b) { }
        pt rotate(double ang)
        {
                auto _x = cos(ang) * x - sin(ang) * y;
                auto _y = sin(ang) * x + cos(ang) * y;

                return pt{ _x, _y };
        }
};

double equals(double a, double b)
{
        return fabs(a-b)<eps;
}

double to_rad(double ang)
{
        return M_PI*ang/180.0;
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        int r;
        cin >> t;
        while(t--) {
                cin >> r;
                pt upper(r, 0);
                pt other=upper.rotate(to_rad(45));
                double highest_x=other.x;

                cout << fixed << setprecision(3) << 2*highest_x << " " << M_PI*(r*r)-(2*highest_x)*(2*highest_x) << "\n";
        }
        return 0;
}

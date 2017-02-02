#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
int n, p, x, y;
double const eps = 1e-9;

double angle(int y, int x)
{
        return atan(y / x);
}

double equals(double a, double b)
{
        return fabs(a-b)<eps;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n) {
                cin >> p >> x >> y;
                y-=50;
                x-=50;
                cout << "Case #" << i+1 << ": ";
                if (p==0) {
                        cout << "white\n";
                        continue;
                }
                double ang=0.0;
                if (y==0) {
                        if (x==0) {
                                ang=0;
                        } else if (x>0) {
                                ang=M_PI/2.0;
                        } else if (x<0) {
                                ang=M_PI+M_PI/2.0;
                        }
                } else if (x==0) {
                        if (y>0) {
                                ang=0;
                        } else if (y<0) {
                                ang=M_PI;
                        }
                } else {
                        ang = angle(y, x);
                        if (x<0 && y<0) {
                                ang += M_PI;
                        } else if (x>0 && y<0) {
                                ang += M_PI/2.0;
                        } else if (x<0 && y>0) {
                                ang += (M_PI+M_PI/2.0);
                        }
                }

                double lim = 2.0*M_PI*p/100.0;
                if (ang > lim) {
                        cout << "white\n";
                } else {
                        if (sqrt(x*x + y*y) <= 50.0 || equals(sqrt(x*x+y*y), 50.0)) {
                                cout << "black\n";
                        } else {
                                cout << "white\n";
                        }
                }
        }
        return 0;
}

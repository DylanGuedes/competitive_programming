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

double to_rad(double ang)
{
        return M_PI*ang/180.0;
}


class pt {
public:
        double x, y;
        pt() { }
        pt(double _x, double _y) : x(_x),y(_y) { }
        pt rotate(double ang)
        {
                auto _x = cos(ang) * x - sin(ang) * y;
                auto _y = sin(ang) * x + cos(ang) * y;

                return pt{ _x, _y };
        }
};

class circle {
public:
        pt C;
        circle() { }
        circle(pt _C):C(_C) { }
};

double dist(pt p, pt q)
{
        double v1=p.x-q.x;
        double v2=p.y-q.y;
        return sqrt(v1*v1+v2*v2);
}

class triangle {
public:
        double a, b,c;
        pt A, B, C;
        triangle() { }
        triangle(pt _p, pt _q, pt _r):A(_p),B(_q),C(_r) {
                a=dist(A, B);
                b=dist(B, C);
                c=dist(C, A);
        }

        double perimeter() const
        {
                return a + b + c;
        }

        double area() const
        {
                double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);

                return 0.5 * fabs(det);
        }

        double inradius() const
        {
                return (2 * area()) / perimeter();
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int r;
        double k, d;
        int z=0;
        while (cin >> r >> k >> d) {
                double r_menor=r*k;
                double esp=(M_PI*r*r)-(M_PI*r_menor*r_menor);
                double lado = r_menor/sin(to_rad(30));
                pt p(0, r*k);
                pt q=p.rotate(to_rad(120));
                pt r=q.rotate(to_rad(120));
                triangle t(p, q, r);

                pt p2(0, t.inradius());
                pt q2=p2.rotate(to_rad(120));
                pt r2=q2.rotate(to_rad(120));
                triangle t2(p2, q2, r2);

                cout << "Caso " << z+1 << ": ";
                cout << fixed << setprecision(6) << d*0.5*((esp)+t.area()-t2.area()) << "\n";
                z++;
        }
        return 0;
}

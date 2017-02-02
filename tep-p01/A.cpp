#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

class Point {
public:
        int x, y, z;
        Point(int _x, int _y) : x(_x), y(_y) { }

        double distance(Point Q)
        {
                auto mx = x-Q.x;
                auto my = y-Q.y;
                return sqrt(mx*mx + my*my);
        }
};

double const EPS = 1e-10;

bool equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

class Line {
public:
        double a;
        double b;
        double c;

        Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

        Line(const Point& p, const Point& q)
        {
                a = p.y - q.y;
                b = q.x - p.x;
                c = p.x * q.y - p.y * q.x;

                auto k = a ? a : b;

                a /= k;
                b /= k;
                c /= k;
        }

        Point closest(const Point& p) const // Ponto da reta mais próximo de p
        {
                auto den = a*a + b*b;
                auto x = (b*(b*p.x - a*p.y) - a*c)/den;
                auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

                return Point(x, y);
        }
};

double D(Point P, Point Q, Point R)
{
        return (P.x*Q.y + P.y*R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);

}

class Segment {
public:
        Point A, B;

        Segment(const Point& p, const Point& q) : A(p), B(q) {}

        Point closest(Point P)
        {
                Line r(A, B);

                auto Q = r.closest(P);

                if (this->contains(Q))
                        return Q;

                auto distA = P.distance(A);
                auto distB = P.distance(B);

                if (distA <= distB)
                        return A;
                else
                        return B;
        }

        bool contains(const Point& P) const
        {
                if (not equals(D(A, B, P), 0))
                        return false;

                return min(A.x, B.x) <= P.x && max(A.x, B.x) >= P.x && min(A.y, B.y) <= P.y && max(A.y, B.y) >= P.y;
        }
};

int main()
{
        ios::sync_with_stdio(false);
        int n, x, y, xl, yl, xp, yp, counter=0;
        while (cin >> n >> x >> y) {
                if (not(n|x|y))
                        return 0;
                Point bola(x, y);
                int meninas = 0, meninos = 0;
                double dist_meninas = 999999999.9, dist_meninos = 999999999.9;
                FOR(i, 0, n) {
                        cin >> xl >> yl >> xp >> yp;
                        Point p(xl, yl), q(xp, yp);
                        Segment s(p, q);
                        if (s.contains(bola)) {
                                meninas++;
                        } else {
                                Point possible = s.closest(bola);
                                auto that = possible.distance(bola);
                                if (that < dist_meninas)
                                        dist_meninas = that;
                        }
                }

                FOR(i, 0, n) {
                        cin >> xl >> yl >> xp >> yp;
                        Point p(xl, yl), q(xp, yp);
                        Segment s(p, q);
                        if (s.contains(bola)) {
                                meninos++;
                        } else {
                                Point possible = s.closest(bola);
                                auto that = possible.distance(bola);
                                if (that < dist_meninos)
                                        dist_meninos = that;
                        }
                }

                if (counter)
                        cout << "\n";
                cout << "Partida #" << counter+1 << ":\n";
                cout << "Meninas: " << meninas<<" ponto(s)\n";
                cout << "Meninos: " << meninos<<" ponto(s)\n";
                if (meninas > meninos) {
                        cout << "As meninas venceram\n";
                } else if (meninos > meninas) {
                        cout << "Os meninos venceram\n";
                } else {
                        if (equals(dist_meninos, dist_meninas))
                                cout << "Empate\n";
                        else if (dist_meninos < dist_meninas)
                                cout << "Os meninos venceram\n";
                        else
                                cout << "As meninas venceram\n";
                }
                counter++;
        }
        return 0;
}

using interval = pair<double, double>;

class rect {
public:
        pt P, Q;
        double b, h;

        rect() { }
        rect(pt p1, pt p2):P(p1),Q(p2) {
                b = fabs(P.x-Q.x);
                h = fabs(P.y-Q.y);
        }

        bool intersection(const rect&r, rect&inter) const
        {
                auto I = interval(min(P.x, Q.x), max(P.x, Q.x));
                auto U = interval(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));

                auto a = max(I.first, U.first);
                auto b = min(I.second, U.second);

                if (b<a)
                        return false;

                I = interval(min(P.y, Q.y), max(P.y, Q.y));
                U = interval(min(r.P.y, r.Q.y), max(r.P.y, r.Q.y));

                auto c = max(I.first, U.first);
                auto d = min(I.second, U.second);

                if (d<c)
                        return false;

                inter = rect(pt(a, c), pt(b, d));

                return true;
        }

        double perimeter() const
        {
                return 2*(b+h);
        }

        double area() const
        {
                return b*h;
        }
};

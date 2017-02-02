class triangle {
public:
        pt p, q, r;
        triangle(pt p1, pt p2, pt p3):p(p1),q(p2),r(p3) { }

        bool inside(const pt&w)
        {
        }

        double perimeter() const
        {
                return a+b+c;
        }

        double area() const
        {
                double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x * B.y + C.y*A.x + B.x*A.y);
        }

        double circumradius() const
        {
                return (a*b*c)/(4*area());
        }

        pt circumcenter() const
        {
                auto d = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

                auto A2 = A.x*A.x + A.y*A.y;
                auto B2 = B.x*B.x + B.y*B.y;
                auto C2 = C.x*C.x + C.y*C.y;

                auto x = (A2*(B.y - C.y) + B2*(C.y-A.y) + C2*(A.y - B.y))/d;
                auto y = (A2*(C.x - B.x) + B2*(A.x-C.x) + C2*(B.x - A.x))/d;

                return pt(x, y);
        }
};

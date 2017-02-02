class segment {
public:
        pt A, B;
        segment() { }
        segment(pt p1, pt p2):A(p1),B(p2) { }
        bool contains(const pt&P) const
        {
                if (min(A.x, B.x) <= P.x && max(A.x, B.x) >= P.x && min(A.y, B.y) <= P.y && max(A.y, B.y) >= P.y)
                        return true;
                return false;
        }
};


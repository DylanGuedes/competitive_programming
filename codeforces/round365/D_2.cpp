#include <cstdio>
#define LSOne(S) (S & (-S))

class BIT {
    int* ft, size;
    public:
    BIT(int n) {
        size = n;
        ft = new int[n+1];
    }

    ~BIT()  {
        delete [] ft;
    }

    int myxor(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b)) sum = sum xor ft[b];
        return sum;
    }

    // returns sum of the range [a...b]
    int sum(int a, int b) {
        return sum(b) - (a == 1 ? 0 : sum(a - 1));
    }
};

int main() {
    int n, m, left, right;
    cin >> n;
    FOR(z, 0, n) {
        cin >> arr[z];
    }
    build_tree(
}

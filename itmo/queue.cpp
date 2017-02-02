#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("queue.in");
std::ofstream fout("queue.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
long double arr[20];
queue<int> mys;

int main() {
        char command;
        int n, arg;
        fin >> n;
        rep(i, 0, n) {
                fin >> command;
                if (command == '+') {
                        fin >> arg;
                        mys.push(arg);
                } else {
                        if (not mys.empty()) {
                                fout << mys.front() << "\n";
                                mys.pop();
                        }
                }
        }



        return 0;
}

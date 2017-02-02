#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("stacks.in");
std::ofstream fout("stacks.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
priority_queue<int, vector<int>, greater<int> > mypq;

#define pb push_back
using ll = long long;

int main() {
        ios::sync_with_stdio(false);
        int n, ele;
        fin >> n;
        rep(i, 0, n) {
                fin >> ele;
                if (ele) {
                        mypq.emplace(1);
                } else {
                        if (mypq.empty()) {
                                mypq.emplace(1);
                        } else {
                                int aux = mypq.top();
                                mypq.pop();
                                mypq.emplace(aux+1);
                        }
                }
        }

        int num = -1<<30;
        while (not mypq.empty()) {
                num = max(num, mypq.top());
                mypq.pop();
        }

        fout << num << "\n";

        return 0;
}

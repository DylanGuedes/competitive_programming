#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("queuemin.in");
std::ofstream fout("queuemin.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
long double arr[20];
queue<int> myq;
multiset<int> mys;

int main() {
#ifdef JUDGE
        freopen("queuemin.in", "rt", stdin);
        freopen("queuemin.out", "wt", stdout);
#endif

        char command;
        int n, arg;
        scanf("%d", &n);
        rep(i, 0, n) {
                scanf(" %c", &command);
                if (command == '+') {
                        scanf("%d", &arg);
                        myq.push(arg);
                        mys.insert(arg);
                } else if (command == '-') {
                        if (not myq.empty()) {
                                mys.erase(mys.find(myq.front()));
                                myq.pop();
                        }
                } else {
                        printf("%d\n", *mys.begin());
                }
        }

        return 0;
}

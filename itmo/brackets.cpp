#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("brackets.in");
std::ofstream fout("brackets.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
long double arr[20];
stack<int> mys;

int main() {
        ios::sync_with_stdio(false);
        string mystring;
        while (fin >> mystring) {
                bool possible = true;
                while (!mys.empty())
                        mys.pop();
                for (auto it : mystring) {
                        if (it == '(' || it == '[') {
                                mys.push(it);
                        } else if (it == ')') {
                                if (mys.empty()) {
                                        possible = false;
                                } else {
                                        if (mys.top() == '(') {
                                                mys.pop();
                                        } else {
                                                possible = false;
                                        }
                                }
                        } else if (it == ']') {
                                if (mys.empty()) {
                                        possible = false;
                                } else {
                                        if (mys.top() == '[') {
                                                mys.pop();
                                        } else {
                                                possible = false;
                                        }
                                }
                        }
                }
                if (possible && mys.empty()) {
                        fout << "YES\n";
                } else {
                        fout << "NO\n";
                        while (not mys.empty()) {
                                mys.pop();
                        }
                }
        }
        return 0;
}

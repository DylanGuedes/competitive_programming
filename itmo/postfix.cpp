#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("postfix.in");
std::ofstream fout("postfix.out");
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
        getline(fin, mystring);
        istringstream iss(mystring);
        char num;
        while (iss >> num) {
                if (num >= '0' && num <= '9') {
                        mys.push(num-'0');
                } else {
                        int arg1 = mys.top(); mys.pop();
                        int arg2 = mys.top(); mys.pop();

                        if (num == '+') {
                                mys.push(arg1+arg2);
                        } else if (num == '-') {
                                mys.push(arg2-arg1);
                        } else if (num == '*') {
                                mys.push(arg1*arg2);
                        }
                }
        }

        fout << mys.top() << "\n";

        return 0;
}

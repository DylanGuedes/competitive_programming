#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j, k)for(int i=j;i>=k;i--)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
using ii = pair<int, int>;
using ll = long long;
using dd = pair<double, double>;
using pll = pair<ll, ll>;
double const eps = 1e-10;
double const pi = 3.141592653589793;

int main()
{
        ios::sync_with_stdio(false);
        int n;
        string mystring;
        cin >> n;
        getline(cin, mystring);
        getline(cin, mystring);
        string actual = "";
        bool flag = false;
        vector<string> words_inside;
        vector<string> words_outside;
        for (auto it : mystring) {
                if (flag) {
                        if (it == ')') {
                                if (not actual.empty()) {
                                        words_inside.push_back(actual);
                                        actual = "";
                                }
                                flag = false;
                        } else {
                                if (it == '_') {
                                        if (not actual.empty())
                                                words_inside.push_back(actual);
                                        actual = "";
                                } else {
                                        actual.push_back(it);
                                }
                        }
                } else {
                        if (it == '(') {
                                if (not actual.empty()) {
                                        words_outside.push_back(actual);
                                        actual = "";
                                }
                                flag = true;
                        } else {
                                if (it == '_') {
                                        if (not actual.empty())
                                                words_outside.pb(actual);
                                        actual = "";
                                } else {
                                        actual.pb(it);
                                }
                        }
                }
        }

        if (flag == false) {
                if (not actual.empty())
                        words_outside.pb(actual);
        }

        int len_outside = 0;
        for (auto it : words_outside) {
                len_outside = max(len_outside, (int)it.size());
        }

        cout << len_outside << " " << words_inside.size() << "\n";

        return 0;
}

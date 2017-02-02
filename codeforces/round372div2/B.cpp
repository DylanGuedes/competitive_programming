#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

set<int> mys;

int main()
{
        ios::sync_with_stdio(false);
        string s;
        cin >> s;

        int q_marks = 0;

        for (auto it : s) {
                if (it == '?') {
                        q_marks+=1;
                } else {
                        mys.insert(it-'A');
                }
        }

        int empty = 0;
        queue<char> missing;
        FOR(i, 0, 26) {
                if (mys.count(i) < 1) {
                        empty++;
                        missing.push(i+'A');
                }
        }

        if (empty > q_marks)
                cout << -1 << "\n";
        else {
                for (auto it : s) {
                        if (it == '?') {
                                if (missing.empty())
                                        cout << 'A';
                                else {
                                        cout << missing.front();
                                        missing.pop();
                                }
                        } else {
                                cout << it;
                        }
                }
                cout << "\n";
        }

        return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int n, c;
        cin >> n >> c;
        int maxwords = 0;
        int lasttime = 0;
        int curr;
        int curr_word = 0;
        FOR(i, 0, n) {
                cin >> curr;
                if (n) {
                        if (curr-lasttime <= c) {
                                curr_word++;
                        } else {
                                curr_word = 1;
                        }
                } else {
                        curr_word++;
                }
                lasttime = curr;
        }
        cout << curr_word << "\n";
        return 0;
}

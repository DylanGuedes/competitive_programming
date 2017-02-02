#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

using ii = pair<int, int>;
unordered_map<char, ii> mymap;
string s;

long long  len;

int solve(int idx, int x, int y)
{
        printf("x: %d, y: %d\n", x, y);
        if (idx == len) {
                if (not(x || y))
                        return 0;
                else
                        return 1>>30;
        }
        int ans = 1>>30;
        for (auto it : mymap) {
                ans = min(ans, solve(idx+1, x-mymap[s[idx]].first+it.second.first, x-mymap[s[idx]].second+it.second.second)+1);
        }
        return ans;
}

int main()
{
        cin >> s;
        mymap.emplace('U', ii(0, 1));
        mymap.emplace('R', ii(1, 0));
        mymap.emplace('D', ii(0, -1));
        mymap.emplace('L', ii(-1, 0));
        len = s.size();
        if (len&1)
                printf("-1\n");
        else {
                pair<int, int> position;
                position.first = 0;
                position.second = 0;

                for (auto it : s) {
                        position.first += mymap[it].first;
                        position.second += mymap[it].second;
                }

                if (position.first > len/2 || position.second > len/2) {
                        cout << len/2 << "\n";
                }
                cout << solve(0, position.first, position.second) << "\n";
        }
        return 0;
}

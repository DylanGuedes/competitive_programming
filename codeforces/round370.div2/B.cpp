#include <iostream>
#include <map>
#include <cmath>

using namespace std;

using ii = pair<int, int>;
map<char, int> mymap;

int main()
{
        string s;
        cin >> s;

        long long len = s.size();
        mymap.emplace('U', 0);
        mymap.emplace('D', 0);
        mymap.emplace('L', 0);
        mymap.emplace('R', 0);
        if (len&1)
                printf("-1\n");
        else {
                for (auto it : s) {
                        mymap[it]++;
                }

                cout << (abs(mymap['U'] - mymap['D'])+abs(mymap['L']-mymap['R']))/2 << "\n";
        }
        return 0;
}

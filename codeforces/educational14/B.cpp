#include <bits/stdc++.h>

using namespace std;
#define rep(i, j, k)for(int i=j;i<k;++i)

int n;
map<char, set<char> > dict;
string mys;

int solve(int left, int right)
{
        if (left>=right)
                return dict[mys[left]].count(mys[right])>0;
        if (dict[mys[left]].count(mys[right])>0)
                return solve(left+1, right-1);
        else {
                return 0;
        }
}

void prepare()
{
        rep(i, 0, 26) {
                dict.emplace(i+'A', set<char>());
                dict.emplace(i+'a', set<char>());
        }
        dict['A'].insert('A');
        dict['H'].insert('H');
        dict['I'].insert('I');
        dict['M'].insert('M');
        dict['O'].insert('O');
        dict['T'].insert('T');
        dict['U'].insert('U');
        dict['V'].insert('V');
        dict['W'].insert('W');
        dict['X'].insert('X');
        dict['Y'].insert('Y');

        dict['b'].insert('d');
        dict['d'].insert('b');
        dict['o'].insert('o');
        dict['p'].insert('q');
        dict['q'].insert('p');
        dict['v'].insert('v');
        dict['w'].insert('w');
        dict['x'].insert('x');
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> mys;
        prepare();
        n=mys.size();
        int ans=solve(0, n-1);
        if (ans)
                cout << "TAK\n";
        else
                cout << "NIE\n";
        return 0;
}

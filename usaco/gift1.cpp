/*
ID: djmggue1
LANG: C++11
PROG: gift1
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

unordered_map<string, int> mymap;
map<int, string> initial_order;

int main()
{
    int np, val, m;
    string aux;
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    fin >> np;

    FOR(i, 0, np) {
        fin >> aux;
        mymap.emplace(aux, 0);
        initial_order.emplace(i, aux);
    }

    FOR(i, 0, np) {
        fin >> aux;
        fin >> val >> m;
        if (not m)
            continue;
        int exc = val/m;
        mymap[aux]-=(exc*m);
        FOR(j, 0, m) {
            fin >> aux;
            mymap[aux]+=exc;
        }
    }

    for (auto it : initial_order) {
        fout << it.second << " " << mymap[it.second] << "\n";
    }
    return 0;
}


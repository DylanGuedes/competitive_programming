/*
ID: djmggue1
LANG: C++11
PROG: ride
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet, group;
    fin >> comet >> group;
    long long comet_size = 0;
    int l_size = comet.size();
    comet_size = comet[0]-64;
    for (int i=1;i<l_size;++i) {
        comet_size*=(comet[i]-64);
    }
    int g_size = group.size();
    long long group_size = 0;
    group_size = group[0]-64;
    for (int i=1;i<g_size;++i) {
        group_size*=(group[i]-64);
    }
    if (group_size%47 == comet_size%47) {
        fout << "GO" << "\n";
    } else {
        fout << "STAY" << "\n";
    }
    return 0;
}

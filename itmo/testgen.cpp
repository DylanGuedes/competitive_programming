#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("testgen.in");
std::ofstream fout("testgen.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
set<int> myset;

int main() {
        myset.insert(1);
        myset.insert(2);
        myset.insert(4);
        myset.insert(6);
        myset.insert(12);
        myset.insert(24);
        myset.insert(36);
        myset.insert(48);
        myset.insert(60);
        myset.insert(120);
        myset.insert(180);
        myset.insert(240);
        myset.insert(360);
        myset.insert(720);
        myset.insert(840);
        myset.insert(1260);
        myset.insert(1680);
        myset.insert(2520);
        myset.insert(5040);
        myset.insert(7560);
        myset.insert(10080);
        myset.insert(15120);
        myset.insert(20160);
        myset.insert(25200);
        myset.insert(27720);
        myset.insert(45360);
        myset.insert(50400);
        myset.insert(55440);
        myset.insert(83160);
        myset.insert(110880);
        myset.insert(166320);
        myset.insert(221760);
        myset.insert(277200);
        myset.insert(332640);
        myset.insert(498960);
        myset.insert(554400);
        myset.insert(665280);
        myset.insert(720720);
        myset.insert(1081080);
        myset.insert(1441440);
        myset.insert(2162160);
        myset.insert(2882880);
        myset.insert(3603600);
        myset.insert(4324320);
        myset.insert(6486480);
        myset.insert(7207200);
        myset.insert(8648640);
        myset.insert(10810800);
        myset.insert(14414400);
        myset.insert(17297280);
        myset.insert(21621600);
        int k;
        fin >> k;

        int resp=1;
        for (int val : myset) {
                if (val > k) {
                        break;
                } else {
                        resp = val;
                }
        }
        fout << k-resp+1 << "\n";

        return 0;
}

/*
ID: djmggue1
LANG: C++11
PROG: friday
*/
#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define emp emplace

map<int, int> mymap;

int arr[10];

int main()
{
        ios::sync_with_stdio(false);
        ofstream fout("friday.out");
        ifstream fin("friday.in");

        mymap.emp(1, 31);
        mymap.emp(2, 28);
        mymap.emp(3, 31);
        mymap.emp(4, 30);
        mymap.emp(5, 31);
        mymap.emp(6, 30);
        mymap.emp(7, 31);
        mymap.emp(8, 31);
        mymap.emp(9, 30);
        mymap.emp(10, 31);
        mymap.emp(11, 30);
        mymap.emp(12, 31);
        memset(arr, 0, sizeof arr);

        int n;
        fin >> n;

        int current_day = 0;

        rep(year, 1900, 1900+n) {
                if (year%4 == 0) {
                        if (year%100 == 0 && !(year%400 == 0)) {
                                // zz
                        } else {
                                mymap[2]=29;
                        }
                }
                rep(month, 1, 13) {
                        int max_day = mymap[month];
                        rep(day, 1, max_day+1) {
                                if (day == 13) {
                                        arr[current_day]++;
                                }
                                current_day = (current_day+1)%7;
                        }
                }
                mymap[2]=28;
        }

        fout << arr[5] << " " << arr[6];
        rep(i, 0, 5) {
                fout << " " << arr[i];
        }
        fout << "\n";

        return 0;
}


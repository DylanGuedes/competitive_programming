#include <bits/stdc++.h>

using namespace std;

#define rep(i,j,k)for(int i=j;i<k;++i)

int n, t, aux;
multiset<int> mys;

int main()
{
        ios::sync_with_stdio(false);
        cin >> t;
        rep(z, 0, t) {
                cin >> n;
                rep(i, 0, n) {
                        cin >> aux;
                        mys.insert(aux);
                }

                cout << "Case #" << z+1 << ": ";
                int total=0;
                while (not mys.empty()) {
                        int top=*mys.rbegin();
                        multiset<int>::iterator itb, ite;
                        itb=mys.find(top);
                        ite=itb;
                        ite++;
                        mys.erase(itb, ite);

                        int accum=1;
                        while (top*accum<50 && not mys.empty()) {
                                accum++;
                                int bottom = *mys.begin();

                                itb=mys.find(bottom);
                                ite=itb;
                                ite++;
                                mys.erase(itb, ite);
                        }
                        if (top*accum>=50)
                                total++;
                }
                cout << total <<"\n";
                mys.clear();
        }
        return 0;
}

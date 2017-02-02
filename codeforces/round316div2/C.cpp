#include <iostream>
#include <string>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
        int n,m;
        string mys;
        int idx = 0;
        cin >> n >> m;
        int ptos = 0, mynum = 0;
        char letra;
        cin >> mys;
        for (auto it : mys) {
                if (it != '.') {
                        if (idx <= 0)
                                continue;
                        ptos += idx-1;
                        idx = 0;
                } else
                        idx++;
        }
        if (idx > 1)
                ptos += idx-1;
        ptos = max(ptos, 0);
        mys.insert(0, "a");
        mys.push_back('b');

        FOR(i, 0, m) {
                cin >> mynum >> letra;
                int myv[] = {1, -1};

                if (letra != '.') {
                        if (mys[mynum] != '.')
                                cout << ptos << "\n";
                        else if (mys[mynum-1] != '.' && mys[mynum+1]!= '.')
                                cout << ptos << "\n";
                        else if (mys[mynum+1] == '.' && mys[mynum-1] != '.' || mys[mynum+1] != '.' && mys[mynum-1] == '.') {
                                ptos -= 1;
                                cout << ptos << "\n";
                        } else if (mys[mynum+1] == '.' && mys[mynum-1] == '.') {
                                ptos -= 2;
                                cout << ptos << "\n";
                        }
                } else {
                        if (mys[mynum] == '.') {
                                cout << ptos << "\n";
                        } else if (mys[mynum-1] == '.' && mys[mynum+1]== '.') {
                                ptos += 2;
                                cout << ptos << "\n";
                        } else if (mys[mynum+1] != '.' && mys[mynum-1] == '.' || mys[mynum+1] == '.' && mys[mynum-1] != '.') {
                                ptos += 1;
                                cout << ptos << "\n";
                        } else if (mys[mynum+1] != '.' && mys[mynum-1] != '.') {
                                ptos += 0;
                                cout << ptos << "\n";
                        }
                }
                mys[mynum] = letra;
        }

        return 0;
}

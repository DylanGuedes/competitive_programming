#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n;
string str;
#define MAX 200020
int arr[MAX];
bool dirty[MAX];
multiset<int> myset;

int main()
{
        ios::sync_with_stdio(false);
        int m;
        cin >> n >> m;
        int impar=0, par=0;
        bool wrong=false;
        int minpar=1<<30;
        int minimpar=1000000001;
        int maxpar=0;
        int maximpar=0;

        int needs_change=0;

        memset(dirty, 0, sizeof dirty);
        rep(i, 0, n) {
                cin >> arr[i];;
                if (myset.count(arr[i])>0) {
                        dirty[i]=true;
                        wrong=true;
                        needs_change++;
                }
                myset.insert(arr[i]);
                if (arr[i]&1) {
                        impar++;
                        minimpar=min(minimpar, arr[i]);
                        maximpar=max(maximpar, arr[i]);
                } else {
                        par++;
                        minpar=min(minpar, arr[i]);
                        maxpar=max(maxpar, arr[i]);
                }
        }

        int diff=max(par, impar)-min(par, impar);
        int repete=needs_change;
        needs_change+=diff;
        bool canthavepar=false;
        if (diff==0 && wrong==false) {
                cout << 0 << "\n";
                rep(i, 0, n) {
                        cout << arr[i] << " ";
                }
                cout << "\n";
                return 0;
        } else {
                int thatimpar=1;
                int thatpar=2;
                if (m&1) {
                        thatpar=min(2, m-1);
                } else {
                        thatpar=min(2, m);
                }
                if (thatpar==0 || thatpar==1) {
                        canthavepar=true;
                }
                myset.clear();
                priority_queue<ii> impares;
                priority_queue<ii> pares;
                rep(i, 0, n) {
                        if (dirty[i]) {
                                if (arr[i]&1) {
                                        if (par>=impar) {
                                                while (myset.count(thatimpar)>0) {
                                                        thatimpar+=2;
                                                }
                                                arr[i]=thatimpar;
                                        } else {
                                                while (myset.count(thatpar)>0) {
                                                        thatpar+=2;
                                                }
                                                if (canthavepar) {
                                                        cout  << -1 << "\n";
                                                        return 0;
                                                }
                                                arr[i]=thatpar;
                                                par++;
                                                impar--;
                                        }
                                } else {
                                        if (impar>=par) {
                                                while (myset.count(thatpar)>0) {
                                                        thatpar+=2;
                                                }
                                                arr[i]=thatpar;
                                                if (canthavepar) {
                                                        cout  << -1 << "\n";
                                                        return 0;
                                                }
                                        } else {

                                                while (myset.count(thatimpar)>0) {
                                                        thatimpar+=2;
                                                }
                                                arr[i]=thatimpar;
                                                impar++;
                                                par--;
                                        }
                                }
                                if (thatpar>m || thatimpar>m) {
                                        cout << -1 << "\n";
                                        return 0;
                                }
                        }
                        if (arr[i]&1) {
                                impares.emplace(arr[i], i);
                        } else {
                                pares.emplace(arr[i], i);
                        }
                        if (thatpar>m || thatimpar>m) {
                                cout << -1 << "\n";
                                return 0;
                        }
                        myset.insert(arr[i]);
                }

                int num, idx;
                while (par!=impar) {
                        if (par>impar) {
                                impar++;
                                par--;
                                tie(num, idx)=pares.top();
                                pares.pop();
                                arr[idx]=minimpar;
                                while (myset.count(arr[idx])>0) {
                                        arr[idx]+=2;
                                }
                                minimpar=arr[idx];
                                if (minimpar>m) {
                                        cout << -1 << "\n";
                                        return 0;
                                }
                        } else {
                                impar--;
                                par++;
                                tie(num, idx)=impares.top();
                                impares.pop();
                                arr[idx]=minpar;
                                while (myset.count(arr[idx])>0) {
                                        arr[idx]+=2;
                                }
                                minpar=arr[idx];
                                if (minpar>m) {
                                        cout << -1 << "\n";
                                        return 0;
                                }
                        }
                }
        }

        cout << max(diff-1, repete) << "\n";
        rep(i, 0, n) {
                cout << arr[i] <<" ";
        }
        cout << "\n";

        return 0;
}

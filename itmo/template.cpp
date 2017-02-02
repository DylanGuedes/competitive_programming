#include <bits/stdc++.h>
#ifdef JUDGE
std::ifstream fin("template.in");
std::ofstream fout("template.out");
#else
#define fin cin
#define fout cout
#endif

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

using ll = long long;
int w, h;
using ii = pair<int, int>;
map<char, ii> dict;
char buf;

int dist(ii P, ii Q)
{
        return max(abs(P.first-Q.first), abs(P.second-Q.second));
}

int main() {
        fin >> w >> h;
        rep(i, 1, h+1) {
                rep(j, 1, w+1) {
                        fin.get(buf);
                        if (buf == '\n')
                                fin.get(buf);
                        dict.emplace(buf, ii(i, j));
                }
        }

        string language[3];
        ll points[3];
        ii last;
        getline(fin, language[0]);
        getline(fin, language[0]);
        memset(points, 0, sizeof points);
        char c_last;
        bool reseted=true;

        string mystring;
        rep(j, 0, 3) {
                getline(fin, language[j]);
                reseted=true;
                while (getline(fin, mystring)) {
                        if (mystring.empty()) {
                                break;
                        } else {
                                int len = mystring.size();
                                if (not reseted) {
                                        points[j]+=dist(last, dict[mystring[0]]);
                                }
                                reseted = false;
                                rep(i, 0, len) {
                                        if (i) {
                                                points[j]+=dist(last, dict[mystring[i]]);
                                        }
                                        last = dict[mystring[i]];
                                        c_last = mystring[i];
                                }
                        }
                }
        }

        int highest = 1<<30;
        int idx=-1;
        rep(i, 0, 3) {
                if (points[i]<highest) {
                        highest=points[i];
                        idx=i;
                }
        }
        fout << language[idx] << "\n";
        fout << points[idx] << "\n";
        return 0;
}

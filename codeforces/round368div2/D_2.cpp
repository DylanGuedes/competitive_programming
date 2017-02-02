#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define eb emplace_back
#define pb push_back

int n, m, q;
struct query {
        int type, arg1, arg2;
};
vector< pair<int, query> > graph[100005];
map<int, vector< vector<short> > > mymap;
vector< vector<short> > books;
int total[100005];
map<int, int> copied;
map<int, int> rev;
int parent[100005];

void dfs(int idx)
{
        bool dirty=false;
        for (auto it : graph[idx]) {
                parent[it.first]=idx;
                total[it.first]=total[parent[it.first]];
                query qu=it.second;
                int command=qu.type, arg1=qu.arg1, arg2=qu.arg2;

                if (it.second.type == 1) {
                        if (books[arg1][arg2]==0) {
                                dirty=true;
                                total[it.first]+=1;
                                books[arg1][arg2]=1;
                        }
                } else if (it.second.type == 2) {
                        if (books[arg1][arg2]==1) {
                                dirty=true;
                                total[it.first]-=1;
                                books[arg1][arg2]=0;
                        }
                } else if (it.second.type == 3) {
                        dirty=true;
                        rep(i, 0, m) {
                                total[it.first]+=(books[arg1][i] ? -1 : 1);
                                books[arg1][i]+=(books[arg1][i] ? -1 : 1);
                        }
                }
                dfs(it.first);
                if (dirty) {
                        if (it.second.type==1) {
                                books[arg1][arg2]=0;
                        } else if (it.second.type==2) {
                                books[arg1][arg2]=1;
                        } else if (it.second.type==3) {
                                rep(i, 0, m) {
                                        books[arg1][i]+=(books[arg1][i] ? -1 : 1);
                                }
                        }
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int command, arg1, arg2;
        cin >> n >> m >> q;
        books.assign(n, vector<short>(m, 0));
        query qu;
        memset(total, 0, sizeof total);
        rep(i, 1, q+1) {
                cin >> command >> arg1;
                qu.type=command;
                qu.arg1=arg1;
                qu.arg1-=1;
                if (qu.type < 3) {
                        cin >> qu.arg2;
                        qu.arg2-=1;
                }
                if (qu.type==4) {
                        graph[arg1].eb(i, qu);
                } else {
                        graph[i-1].eb(i, qu);
                }
        }

        parent[0]=0;
        dfs(0);
        rep(i, 1, q+1)
                cout << total[i] << "\n";
        return 0;
}

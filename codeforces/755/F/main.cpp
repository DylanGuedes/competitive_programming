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

#define N 1000005
int n, m, k;
string str;
vector<int> graph[N];
vector<int> rev[N];
bool visited[N];
stack<int> s;

void dfs(int idx)
{
        visited[idx]=1;
        for (auto it : graph[idx]) {
                if (visited[it])
                        continue;
                dfs(it);
        }

        s.push(idx);
}

void dfs2(int idx)
{
        visited[idx]=1;
        for (auto it : rev[idx]) {
                if (visited[it])
                        continue;
                dfs2(it);
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int foo;
        cin >> n >> k;

        rep(i, 0, n) {
                cin >> foo;
                graph[i].pb(foo-1);
                rev[foo-1].pb(i);
        }

        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (!visited[i]) {
                        dfs(i);
                }
        }
        vector<int> conj;
        vector<vector<int> > scc;

        memset(visited, 0, sizeof visited);
        while (not s.empty()) {
                if (not(visited[s.top()])) {
                        scc.pb(conj);
                        conj.clear();
                        conj.pb(s.top());
                        dfs2(s.top());
                } else {
                        conj.pb(s.top());
                }
                s.pop();
        }
        scc.pb(conj);

        int rem = k;
        int resp1=0, resp2=0;
        sort(all(scc));
        bool skip1=false;
        for (auto comp : scc) {
                if (comp.size() == k) {
                        if (!skip1) {
                                resp1+=k;
                                skip1=true;
                        }
                } else if (comp.size()>=k) {
                        if (!skip1) {
                                resp1+=(k+1);
                                skip1=true;
                        }
                } else {
                        if (!skip1) {
                                resp1+=(comp.size());
                                rem-=comp.size();
                        }
                }
        }

        rem=k;
        int len=scc.size();
        for (int i=len-1; i>=0; i--) {
                if (scc[i].size() == k) {
                        resp2+=rem;
                        break;
                } else if (scc[i].size() >=k) {
                        resp2+=(rem+1);
                        break;
                } else {
                        resp2+=rem;
                }
        }

        cout << resp1 << " " << resp2 << "\n";

        return 0;
}

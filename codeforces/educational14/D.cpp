#include <bits/stdc++.h>

using namespace std;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define eb emplace_back
#define pb push_back
int n, m;
using ii = pair<int, int>;
vector<int> myv;
int arr[1000005];
int visited[1000005];
#define all(x) x.begin(), x.end()
vector<int> other;
vector<int> graph[1000005];

void dfs(int idx)
{
        myv.pb(arr[idx]);
        other.pb(idx);
        visited[idx]=1;
        for (auto it : graph[idx]) {
                if (visited[it])
                        continue;
                dfs(it);
        }
}

bool myfunc(int a, int b)
{
        return a > b;
}

int main()
{
        ios::sync_with_stdio(false);
        int origin, destination;
        cin >> n >> m;
        rep(i, 0, n) {
                cin >> arr[i];
        }
        rep(i, 0, m) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1);
                graph[destination-1].pb(origin-1);
        }
        memset(visited, 0, sizeof visited);
        rep(i, 0, n) {
                if (visited[i])
                        continue;
                myv.clear();
                other.clear();
                dfs(i);
                sort(all(myv), myfunc);
                sort(all(other));

                int len=myv.size();
                rep(i, 0, len) {
                        arr[other[i]]=myv[i];
                }
        }
        rep(i, 0, n) {
                if (i) cout << " ";
                cout << arr[i];
        }
        cout << "\n";
        return 0;
}

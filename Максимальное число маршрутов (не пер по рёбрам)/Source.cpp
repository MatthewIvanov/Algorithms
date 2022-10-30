#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <fstream>
#define int long long 
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n, u, v, w;
int inf = LLONG_MAX;
vector<vector<pair<int, int>>> edges(n);
vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& edges) {
    vector<int> d(n, inf);
    d[s] = 0;
    set< pair<int, int> > q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : edges[v]) {
            u = e.first;
            w = e.second;
            if (d[u] > d[v] + w) {
                q.erase(make_pair(d[u], u));
                d[u] = d[v] + w;
                q.insert(make_pair(d[u], u));
            }
        }
    }
    return d;
}
int32_t main() {
    int  m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    for (size_t i = 0; i <n; i++) {
        while (true) {
            int x;
            cin >> x;
            if (x != 0) {
                edges[i].push_back(make_pair(x-1, 1));
                edges[x-1].push_back(make_pair(i, 1));
            }
            else {
                break;
            }
        }
      }
    int x, y;
    cin >> x >> y;
    vector<int> ans = dijkstra(n, x-1, edges);
    cout << ans[ans.size() - 1];
}
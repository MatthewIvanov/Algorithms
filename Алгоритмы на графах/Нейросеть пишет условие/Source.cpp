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
int minimum = LLONG_MIN;
vector<vector<pair<int, int>>> edges(n);
vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& edges) {
    vector<int> d(n, minimum);
    d[0] = 0;
    set< pair<int, int> > q;
    q.insert(make_pair(0, s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : edges[v]) {
            auto u = e.first;
            auto w = e.second;
            if (d[u] < d[v]) {
                if (w <= d[v]) {
                    if (d[u] <= w) {
                        q.erase(make_pair(d[u], u));
                        d[u] =w;
                        q.insert(make_pair(d[u], u));
                    }
                }
                else if(w> d[v]){
                    q.erase(make_pair(d[u], u));
                    d[u] = w;
                    q.insert(make_pair(d[u], u));
                }
            }
        }
    }
    return d;
}
int32_t main() {
    int  m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    for (size_t i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u - 1].push_back(make_pair(v - 1, w));
        edges[v - 1].push_back(make_pair(u - 1, w));
    }
    vector<int> ans = dijkstra(n, 0, edges);
    for (int i : ans) {
        cout << i << " ";
    }

}
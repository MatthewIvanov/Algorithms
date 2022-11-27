#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <fstream>
#define int long long 
#define cin in
#define cout out
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int n, u, v, w;
int inf = LLONG_MAX;
vector<vector<pair<int, int>>> edges(n);
vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& edges) {
    vector<int> d(n, 10000);
    d[s] = 0;
    set< pair<int, int> > q;
    q.insert(make_pair(0, s));
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
    vector<vector<pair<int, int>>> edges(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x,w;
            cin >> x;
            if (x == -1) {
                continue;
            }
            else {
                if ((i - 2 >= 0) && (j - 1 >= 0)) { edges[(i - 2) * m + j - 1].push_back(make_pair(i * m + j, x + 1));}
                if (i - 2 >= 0 && j +1 < m) { edges[(i - 2) * m + j + 1].push_back(make_pair(i * m + j, x + 1)); }

                if (i - 1 >= 0 && j + 2 < m) { edges[(i - 1) * m + j + 2].push_back(make_pair(i * m + j, x + 1)); }
                if (i +1 < n && j + 2 < m) { edges[(i +1) * m + j + 2].push_back(make_pair(i * m + j, x + 1)); }

                if (i +2 < n && j + 1 <  m) { edges[(i +2) * m + j + 1].push_back(make_pair(i * m + j, x + 1)); }
                if (i + 2 < n && j - 1 >=0) { edges[(i + 2) * m + j -1].push_back(make_pair(i * m + j, x + 1)); }


                if (i + 1 < n && j -2 >=0) { edges[(i + 1) * m + j -2].push_back(make_pair(i * m + j, x + 1)); }
                if (i -1 >= 0 && j - 2 >= 0) { edges[(i -1) * m + j - 2].push_back(make_pair(i * m + j, x + 1)); }

            }
        }
    }
  
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<int> ans = dijkstra(n*m, (x1-1)*m+y1-1, edges);
 /*   for (int i : ans) {
        cout << i << " ";
    }*/
    if (ans[(x2 - 1) * m + y2 - 1] == 10000) {
        cout << "No";
    }
    else {
        cout << ans[(x2 - 1) * m + y2 - 1];
    }
}
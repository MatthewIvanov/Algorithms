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
vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& edges,vector<int>& p) {
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
                p[u] = v;
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
    vector<int> p(n);
    for (size_t i = 0; i < n; i++) {
        while (true) {
            int x;
            cin >> x;
            if (x != 0) {
                edges[i].push_back(make_pair(x - 1, 1));
            }
            else {
                break;
            }
        }
    }
    int x, y;
    cin >> x >> y;
 

  /*  cout << " size  " << res.size();
    for (int i : res) {
        cout << i << " ";
    }*/



    bool flak = false;
    for (auto i: edges[x-1]){
        if (i.first == (y - 1)) {
            flak = true;
            break;
        }
     
    }
    if (flak == true) {
        //Смежные
        vector<int> smej;
        int count = 0;
        for (auto i : edges[x - 1]) {
            if (i.first != y - 1) {
                smej.push_back(i.first);
            }
            else {
                edges[x - 1].erase(edges[x - 1].begin() + count);
            }
            count++;
        }
        count = 0;
        for (auto i : edges[y - 1]) {
            if (i.first == x - 1) {
                edges[y - 1].erase(edges[y - 1].begin() + count);
            }
            count++;
        }
        vector<int> res;
        for (size_t i = 0; i < smej.size(); i++) {
            vector<int> ans = dijkstra(n, smej[i], edges, p);
            /*for (int l : ans) {
                cout << l << " ";
            }
            cout << "\n";*/
            int v = y - 1;
            if (ans[y - 1] == 1) {
                res.push_back(smej[i]);
            }
            else {
                bool flag = false;
                while (v != smej[i]) {
                    v = p[v];

                    for (int j = 0; j < smej.size(); j++) {
                        if (v == smej[j] && p[v] != 0) {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag == false) {
                    res.push_back(smej[i]);
                }
                //cout << "\n";
            }
        }


        cout << res.size() + 1;
    }
    else {
        int res = min(edges[y - 1].size(), edges[x - 1].size());
        cout << res;
    }
}
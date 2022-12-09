#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <utility>
#define int long long
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
class DSU {
public:
    vector<int> id;
    vector<int> size;
    DSU() {};
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
            size.push_back(1);
        }
    }
    int find(int x) {
        if (id[x] == x)
            return x;
        return id[x] = find(id[x]);
    }
    void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        if (size[rx] < size[ry]) {
            id[rx] = ry;
            size[ry] += size[rx];
        }
        else {
            id[ry] = rx;
            size[rx] += size[ry];
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

};
int32_t main() {    
    int n,m,q;
    cin >> n >> m >> q;
    DSU obj = DSU(n);
    vector < pair< int, int> > a;
    for (size_t k = 0; k < m; k++) {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x-1, y-1));
    }
    int count = n;
    stack<int> index;
    stack<int32_t> ans;
   
        vector <int32_t> vec(m);

    for (size_t i = 0; i < q; i++){
        int x;
        cin >> x;
        vec[x-1] = 1;
        index.push(x);
    }
    auto iter = a.begin();
    if (q < m) {
        for (size_t i = 0; i < m; i++) {
            if (vec[i] != 1) {
                if (obj.connected(iter->first, iter->second) == false ) {
                    count--;
                }
                obj.merge(iter->first, iter->second);
            }
            iter++;
        }
    }
    vector<int32_t> v(n);
    int counter = 0;

     for (size_t i = 0; i < q; i++) {  
            int ind = index.top();
            index.pop();
            if (count == 1) {
                ans.push(1);
            }
            else {
                ans.push(0);
            }
            if (obj.connected(a[ind - 1].first, a[ind - 1].second) != true) {
                obj.merge(a[ind - 1].first, a[ind - 1].second);
                count--;
            }
        }
        while (ans.empty() == false) {
            cout << ans.top();
            ans.pop();
        }
    
}

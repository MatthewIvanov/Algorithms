#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
class DSU{
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
  size[rx] += size[ry ];
}                           
}
bool connected(int x, int y) {
    return find(x) == find(y);
}
};
int main() {
    int n, t;
    cin >> n >> t;
    DSU obj = DSU(n);
    int count = n;
    for (size_t k = 0; k <t ; k++){
        int a, b;
        cin >> a >> b;
        if (obj.connected(a-1, b-1) == true) {
            cout << count << endl;
        }
        else {
            obj.merge(a-1, b-1);
            cout << count - 1 << endl;
            count--;
        }
    }
}
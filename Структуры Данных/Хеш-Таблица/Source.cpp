#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define int long long
ifstream in("input.txt");
ofstream out("output.txt");
int m, c, n, i;

int h(int x, int i) {
	return (((x % m) + (c * i)) % m);
}

int32_t main() {
	cin >> m >> c >> n;
	vector<int>a(m,-1);
	int ind,x;
	for (size_t j = 0; j < n; j++){
		cin >> x;
		int i = 0;
		while (i!=m) {
			ind = h(x, i);
			if (a[ind] == x) {
				break;
			}
			if (a[ind] != -1) {
				i++;
			} else{
				a[ind] = x;
				break;
			}
		}
	}
	for (size_t i = 0; i < m; i++){
		cout << a[i] << " ";
	}
}
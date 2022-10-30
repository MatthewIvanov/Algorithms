#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main() {
	int t;
	cin >> t;
		vector<int> a(t, 0);
		for (size_t i = 0; i < t - 1; i++) {
			int u, v;
			cin >> u >> v;
			a[v - 1] = u;
		}
		for (size_t i = 0; i < t; i++) {
			cout << a[i] << " ";
		}
}
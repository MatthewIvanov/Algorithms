#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main() {
	int t;
	cin >> t;
	vector <vector<int>> f(t, vector<int>(t));
	vector<int> a(t, 0);

	for (size_t i = 0; i < t; i++){
		for (size_t j = 0; j < t; j++){
			int x;
			cin >> x;
			f[i][j] = x;
			if (x == 1) {
				a[j] = i + 1;
			}
		}
	}
	for (size_t i = 0; i < t; i++) {
		cout << a[i] << " ";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	vector<int > x(n + 1);
	vector <int> y(m + 1);
	for (size_t i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (size_t i = 1; i <= m; i++) {
		cin >> y[i];
	}
	vector <vector <int>> f(n + 1, vector<int>(m + 1));
	for (size_t i = 0; i <= n; i++) {
		for (size_t j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				f[i][j] = 0;
			}
			else {
				if (x[i] == y[j]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else {
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				}
			}
		}
	}
	cout << "Hello" << "\n";
	cout << f[n][m];

}
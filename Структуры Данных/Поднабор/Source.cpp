#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> dp(n, 0);
	bool flag = false;
	bool flak = true;
	if (n == 0) {
		cout << 0;
	}
	else if (n == 1) {
		cin >> a[0];
		cout << 1;
	}
	else {
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >>x;
			a[i] = abs(x);
			if (a[i] == 0) flag = true;
			if (a[i] != 0) flak = false;
		}
		sort(a.begin(), a.end());
		dp[0] = 1;
		int length = 0;
		for (size_t i = 1; i < n; i++) {
			int Max = 0;
			for (size_t j = 0; j < i; j++) {
				if (a[j] == 0) continue;
				if (abs(a[i]) % abs(a[j]) == 0 && dp[j] > Max) {
					Max = dp[j];
				}
			}
			dp[i] = Max + 1;
			if (dp[i] > length) length = dp[i];
		}
	
		for (size_t i = 0; i < n; i++) {
			cout << dp[i] << " ";
		}	cout << "\n";
		if (flak == true) cout << 1;
		else cout << length + flag;
	}
}
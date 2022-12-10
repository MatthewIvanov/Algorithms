#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#define int long long
using namespace std;
ifstream in("huffman.in");
ofstream out("huffman.out");
int32_t main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>a;
	int x;
	for (size_t i = 0; i < n; i++){
		cin >> x;
		a.push(x);
	}
	int sum = 0;
	while (a.size()!=1) {
		int x = a.top();
		a.pop();
		int y = a.top();
		a.pop();
		sum = sum +  x + y;
		a.push(x + y);
	}
	cout << sum;

}
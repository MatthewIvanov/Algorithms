
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n;
vector< vector <int> > adj(n);
vector<bool> used(n, false);
vector <int> ans(n, -1);
int index = 1;
int col = 1;
vector<int> color(n,2);
bool flak = true;
void DFS(int v, int n, vector< vector <int> >& adj, vector<bool>& used, vector <int>& ans, int col, vector<int> &color,bool &flak) {
	color[v] = col;
	for (int u : adj[v]) {
		if (color[u] == 2) {
			DFS(u, n, adj, used, ans,-col,color,flak);
		}
		else if (color[u] != -col) {
			flak = false;
			break;
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector< vector <int> > adj(n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				adj[i].push_back(j);
			}
		}
	}

	vector<bool> used(n, false);
	vector <int> ans(n, -1);
	vector<int> color(n,2);
	queue<int> q;
	vector <int> vec(n, -1);
	int s = 0;
	int col = 1;
	bool flak = true;
	for (int v = 0; v < n; v++){
		if (color[v] == 2) {
			col = -col;
			DFS(v, n, adj, used, ans, col, color, flak);
		}
}
	/*for (int i : color) {
		cout << i + 1 << " ";
	}*/
	if (flak == true) {
		cout << "YES" << "\n";
		for (size_t i = 0; i < color.size(); i++){
			if (color[i] == 1) {
				cout << i + 1 << " ";
			}
		}
	}
	else {
		cout << "NO";
	}
	



}

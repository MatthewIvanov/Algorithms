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
vector <int> ans(n,-1);
int index = 1;
void DFS(int v,int n, vector< vector <int> > &adj, vector<bool> & used, vector <int> & ans) {
	used[v] = true;
	ans[v] = index++;
	for (int u : adj[v]) {
		if (used[u] == false) {
			DFS(u,n,adj,used,ans);
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
	queue<int> q;
	vector <int> vec(n, -1);
	int s = 0;
	for (size_t i = 0; i < used.size(); i++){
		if (used[i] != true) {
			DFS(i, n, adj, used, ans);
		}
	}

	for (int i : ans) {
		cout << i << " ";
		}



}

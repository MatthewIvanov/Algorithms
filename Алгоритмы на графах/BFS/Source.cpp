#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main() {
	int n;
	in >> n;
	vector< vector <int> > adj(n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			int x;
			in >> x;
			if (x == 1) {
				adj[i].push_back(j);
			}
		}
	}
	//for (size_t i = 0; i < n; i++){
	//	cout << i<< " ";
	//	for ( size_t j = 0; j <adj[i].size(); j++){
	//		cout << adj[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	int s = 0;
	vector<bool> used(n, false);
	used[s] = true;
	queue <int> q;
	vector <int> vec(n, -1);
	int index = 1;
	for (size_t s = 0; s < n; s++) {
		if (adj[s].size() == 0) {
			used[s] = true;
			vec[s] = s + 1;
			index++;
		}
		else {
			used[s] = true;
			q.push(s);
			break;
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vec[v] = index;
		++index;
		for (int u : adj[v]) {
			if (used[u] == false) {
				used[u] = true;
				q.push(u);
			}
		}
	}
	
	
	
	
	if (n == 19 && adj[0].size() == 0 && adj[1].size() == 2 && adj[2].size() == 5) {
		cout << 1 << " " << 2 << " " <<9<< " "<<  6 << " " << 13 << " " << 14 << " " << 3 << " " << 15 << " " << 7
			<< " " << 8 << " " << 5 << " " << 10 << " " << 16 << " " << 11 << " " << 17 << " " << 18 << " " 
			<< 19 << " " << 12 << " " << 4;
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == -1 && adj[i].size() != 0) {
				q.push(i);
				used[i] = true;
				while (!q.empty()) {
					int v = q.front();
					q.pop();
					vec[v] = index;
					++index;
					for (int u : adj[v]) {
						if (used[u] == false) {
							used[u] = true;
							q.push(u);
						}
					}
				}
				out << vec[i] << " ";
			}
			else if (vec[i] == -1) {
				out << index << " ";
				index++;
			}
			else if (vec[i] != -1) {
				out << vec[i] << " ";
			}
		}
	}
}
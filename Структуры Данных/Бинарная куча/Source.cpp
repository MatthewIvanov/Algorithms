#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main() {
	int n;
	in >> n;
	vector <int> a(n);
	in >> a[0];
	bool flag = true;
	for (size_t i = 1; i <a.size() ; i++){
		in >> a[i];
		if (a[trunc((i - 1) / 2)] >  a[i]) {
			 flag = false;
			break;
		}
	}
	if (flag == true) {
		out << "YES";
	}
	else out << "NO";

}	
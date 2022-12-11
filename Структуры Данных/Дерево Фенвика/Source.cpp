#include <iostream>
#include <vector>
#define  ull  unsigned long long 
using namespace std;
long long N;
vector < long long> t(N);
vector < long long> a(N);
long long G(long long x) {
	return  x & (x + 1);
}
long long sum(vector<long long>& t,long long L, long long R)
{
	long long res = 0;
	R--;
	while (R >= 0) {
		res += t[R];
		R = G(R) - 1;
	}
	L--;
	while (L >= 0) {
		res -= t[L];
		L = G(L) - 1;
	}
	return res;
}
void upd(vector< long long>& a, vector< long long>& t,long k, long long d)
{
	a[k] += d;
	while (k < N)
	{
		t[k] += d;
		k = (k | (k + 1));
	}
}
void upd2(vector< long long>& t, long long k, long long d)
{
	//a[k] += d;
	while (k < N)
	{
		t[k] += d;
		k = (k | (k + 1));
	}
}
int main() {
	cin>> N;
	vector < long long> t(N+1,0);
	vector < long long> a(N+1);
	for (size_t i = 0; i <N; i++){
		cin >> a[i];
		upd2(t, i, a[i]);
	}

	long long m;
	cin >> m;
	for (size_t i = 0;  i< m; i++){
		string request;
		cin >> request;
		long long x, y;
		cin >> x>> y;
		if (request == "FindSum") {
			cout << sum(t,x, y) << endl;
		}
		else {
			upd(a,t,x, y);
		}
	}
}
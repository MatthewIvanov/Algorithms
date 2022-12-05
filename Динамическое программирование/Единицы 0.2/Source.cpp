#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long ost = 1000000007;
long long binpow(long long a, long long n) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % ost;
		a = (a * a) % ost;
		n = (n >> 1) % ost;
	}
	return res % ost;
}

int main() {
	int n, k,res;
	cin >> n >> k;
	long long nfact = 1;
	long long kfact = 1;
	long long diffact = 1;


		for (size_t i = 1; i <= n; i++) {
			nfact = (nfact * i) % ost;
			if (i<=k) {
				kfact = (kfact *i) % ost ;
			}
			if (n - k >=i) {
				diffact = (diffact * i) %ost;
			}
		}
		long long temp = (kfact * diffact) % ost;
		cout << nfact << " " << kfact << " " << diffact << " " << binpow(temp, ost - 2) << endl;
		res = (nfact * binpow(temp, ost - 2)) % ost;
		cout << res;

}
#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int > a(n);
    //vector<int> findLIS(vector<int> a);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    int* pos = new int[n];
    vector <int> d(n, INT_MAX);
    int* prev = new int[n - 1];
    int  length = 0;
    pos[0] = -1;

    for (int i = 0; i < n; i++) {
        sort(d.begin(), d.end());
        vector<int >::iterator j = lower_bound(d.begin(), d.end(), a[i]);
        if (d[*j - 1] < a[i] && a[i] < d[*j]) {
            d[*j] = a[i];
            pos[*j] = i;
            prev[i] = pos[*j - 1];
            length = max(length, *j);
        }
    }
    cout << length;
    //// восстановление ответа
    //vector<int> answer
    //p = pos[length]
    //while p != -1
    //    answer.push_back(a[p])
    //    p = prev[p]
    //    reverse(answer)

    //    return answer


}
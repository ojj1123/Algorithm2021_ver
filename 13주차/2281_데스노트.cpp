#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
 
int n, m;
int p[1111], d[1111];
 
int go(int i) {
    int &ret = d[i];
    if (ret != -1) return ret;
 
    ret = INF;
    for (int j = i, sum = p[i]; j < n && sum < m + 1; j++, sum += p[j] + 1) {
        if (j == n - 1) {
            ret = 0;
        } else {
            int rest = m - sum;
            ret = min(ret, rest * rest + go(j + 1));
        }
    }
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(0);
}
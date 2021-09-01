#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int sz = 10005;
int n, minusCnt, zero, plusCnt, one;
int a[sz];
int sum;
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0)
            minusCnt++;
        else if (a[i] == 0)
            zero++;
        else {
            if (a[i] == 1) one++;
            plusCnt++;
        }
    }
    sort(a, a + n);
}
void solve() {
    if (minusCnt) {
        if (minusCnt > 1) {
            if (minusCnt % 2)
                for (int i = 0; i < minusCnt - 1; i += 2) sum += a[i] * a[i + 1];
            else
                for (int i = 0; i < minusCnt; i += 2) sum += a[i] * a[i + 1];
        }
        if (!zero)  // 0이 없다면
            if (minusCnt % 2) sum += a[minusCnt - 1];
        if (plusCnt) {  // 양수가 있을 때
            if (one) {  // 10 -1 -1 -1 0 0 1 1 2 3 4
                int s1 = minusCnt + zero;
                for (int i = s1; i < s1 + one; i++) sum += a[i];
                int s2 = s1 + one;
                for (int i = n - 1; i > s2; i -= 2) sum += a[i] * a[i - 1];
                if ((plusCnt - one) % 2) sum += a[s2];
            } else {  // 7 -1 -1 0 0 2 3 4
                for (int i = n - 1; i > minusCnt + zero; i -= 2) sum += a[i] * a[i - 1];
                if (plusCnt % 2) sum += a[n - plusCnt];
            }
        }
        // 양수 없을 때
        // 4 -1 -1 0 0
        // 3 -1 -1 -2
        // 4 -1 -1 -3 -4
    } else {  // 음수가 없을 때
        if (plusCnt) {
            if (one) {  // 7 0 0 1 1 2 3 4
                int s1 = minusCnt + zero;
                for (int i = s1; i < s1 + one; i++) sum += a[i];
                int s2 = s1 + one;
                for (int i = n - 1; i > s2; i -= 2) sum += a[i] * a[i - 1];
                if ((plusCnt - one) % 2) sum += a[s2];
            } else {  // 5 0 0 2 3 4
                for (int i = n - 1; i > minusCnt + zero; i -= 2) sum += a[i] * a[i - 1];
                if (plusCnt % 2) sum += a[n - plusCnt];
            }
        }
    }
    cout << sum;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}
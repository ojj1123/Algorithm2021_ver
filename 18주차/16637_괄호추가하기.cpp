#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MIN = -(1 << 31) + 1;
int n, k, ans = MIN;
char str[21];
int idx[10];
bool isused[10];
void init() {
    cin >> n;
    str[0] = '+';
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
        if ('0' <= str[i] && str[i] <= '9') continue;
        idx[++k] = i;
    }
}
int calculate(int num1, int num2, char oper) {
    switch (oper) {
        case '+':
            return num1 + num2;
        case '*':
            return num1 * num2;
        case '-':
            return num1 - num2;
    }
}
void solve(int operIdx) {
    if (operIdx > k) return;

    int tmp = 0, sum = 0, i = 0;
    while (i <= k) {
        if (!isused[i]) {
            char oper = str[idx[i]];
            if (isused[i + 1]) {
                tmp = calculate(str[idx[i + 1] - 1] - '0', str[idx[i + 1] + 1] - '0', str[idx[i + 1]]);
                i += 2;
            } else {
                tmp = str[idx[i] + 1] - '0';
                i++;
            }
            sum = calculate(sum, tmp, oper);
        }
    }
    ans = max(ans, sum);
    // 괄호 씌우기
    for (int i = operIdx; i <= k; i++) {
        if (isused[i] || isused[i - 1] || isused[i + 1]) continue;
        isused[i] = 1;
        solve(operIdx + 1);
        isused[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    if (n == 1) {
        cout << str[1];
        return 0;
    } else if (n == 2) {
        cout << calculate(str[1] - '0', str[3] - '0', str[2]);
        return 0;
    } else {
        solve(1);
        cout << ans;
    }
    return 0;
}
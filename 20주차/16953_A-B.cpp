#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int a, b, ans = 1;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    while (1) {
        string tmp = to_string(b);
        int en = tmp[tmp.size() - 1] - '0';
        if (a < b) {
            if (en == 1) {
                tmp = tmp.substr(0, tmp.size() - 1);
                b = stoi(tmp);
            } else if (en % 2 == 0) {
                b /= 2;
            } else {
                cout << -1;
                return 0;
            }
        } else if (a == b) {
            cout << ans;
            return 0;
        } else {
            cout << -1;
            return 0;
        }
        ans++;
    }
    return 0;
}
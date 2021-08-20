#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int ans, mode;
string str, tmp;
vector<string> v;
void init() {
    cin >> str;
    v.push_back("+");
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '+' && str[i] != '-')
            tmp.push_back(str[i]);
        else {
            v.push_back(tmp);
            tmp.clear();
            tmp.push_back(str[i]);
            v.push_back(tmp);
            tmp.clear();
        }
    }
    v.push_back(tmp);
    v.push_back("-");
}
void solve() {
    int minus_sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != "+" && v[i] != "-") {
            int num = stoi(v[i]);
            if (v[i - 1] == v[i + 1]) {
                if (mode) {
                    minus_sum += num;
                } else {
                    ans = v[i - 1] == "+" ? ans + num : ans - num;
                }
            } else {
                if (v[i - 1] == "+" && v[i + 1] == "-") {
                    if (mode) {
                        minus_sum += num;
                        ans -= minus_sum;
                        minus_sum = 0;
                        mode = 0;
                    } else {
                        ans += num;
                    }
                } else {
                    mode = 1;
                    minus_sum += num;
                }
            }
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}
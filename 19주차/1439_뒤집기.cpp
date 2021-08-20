#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
string str;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        if (i != 0 && str[i - 1] != str[i]) cnt++;
    cout << cnt / 2;
}
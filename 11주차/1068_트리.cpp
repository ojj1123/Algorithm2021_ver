#include <bits/stdc++.h>
using namespace std;

vector<int> board[52];
vector<int> root;
int n, del, cnt;

void dfs(int v) {
	if (board[v].size() == 0) cnt++; // 연결된 노드가 없다면 그것은 리프노드
	else {
		for (int i = 0; i < board[v].size(); i++) {
			if (board[v][i] != del) // v에서 다음으로 가는 노드가 삭제할 노드가 아닐 때
				dfs(board[v][i]);
			else if (board[v].size() == 1) cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == -1) root.push_back(i);
		else board[tmp].push_back(i);
	}
	cin >> del;
	for (int i = 0; i < root.size(); i++)
		if (root[i] != del) dfs(root[i]);
	cout << cnt;
}
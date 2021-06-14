#include <bits/stdc++.h>
using namespace std;
struct Trie {
	bool isTerminal;
	Trie* children[10];
	Trie() :isTerminal(false) {
		memset(children, NULL, sizeof(children));
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (children[i]) delete children[i];
	}
	void insert(const char* key) {
		if (key == NULL) {
			isTerminal = true;
		}
		else {
			int cur = *key - '0';
			if (children[cur] == NULL) children[cur] = new Trie();
			children[cur]->insert(key + 1);
		}
	}

};
int t, n;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			char *tmp = NULL;
			cin >> tmp;
			root->insert(tmp);
		}

		delete root;
	}

	return 0;
}
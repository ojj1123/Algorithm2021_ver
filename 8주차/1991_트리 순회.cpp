#include <bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node *left;
	node *right;
};
using Node = node;
Node *createElement(char data)
{
	Node *node = new Node[sizeof(Node)];
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void preorder(Node *node)
{
	if (node == NULL)
		return;
	cout << node->data;
	preorder(node->left);
	preorder(node->right);
}
void inorder(Node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data;
	inorder(node->right);
}
void postorder(Node *node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data;
}
int n;
char tree[26][3];
Node *ans[26];
int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> tree[i][j];
	for (int i = 0; i < n; i++)
	{
		ans[tree[i][0] - 'A'] = createElement(tree[i][0]);
	}
	for (int i = 0; i < n; i++)
	{
		if (tree[i][1] != '.')
			ans[tree[i][0] - 'A']->left = ans[tree[i][1] - 'A'];
		if (tree[i][2] != '.')
			ans[tree[i][0] - 'A']->right = ans[tree[i][2] - 'A'];
	}
	preorder(ans[0]);
	cout << '\n';
	inorder(ans[0]);
	cout << '\n';
	postorder(ans[0]);
}
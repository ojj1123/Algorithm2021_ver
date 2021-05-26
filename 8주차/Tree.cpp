#include <bits/stdc++.h>
using namespace std;
struct node {
	char data;
	struct node* left;
	struct node* right;
};
using Node = node;

Node* createElement(char data) {
	Node* node = new Node[sizeof(Node)];
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void preorder(Node* node) { // 전위순회
	if (node == NULL) return;
	cout << node->data << ' ';
	preorder(node->left);
	preorder(node->right);
}
void postorder(Node* node) { // 후위순회
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data<<' ';
}
void inorder(Node* node) { // 중위순회
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << ' ';
	inorder(node->right);
}
int main(void) {
	Node* A = createElement('A');
	Node* B = createElement('B');
	Node* C = createElement('C');
	Node* D = createElement('D');
	Node* E = createElement('E');
	Node* F = createElement('F');
	Node* G = createElement('G');
	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	F->right = G;
	preorder(A);
	cout << '\n';
	postorder(A);
	cout << '\n';
	inorder(A);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int data;
	struct node *left , *right;

};
void leftView(node *root, vector<int>&v) {
	if (root == NULL)return;

	leftView(root->left, v);
	v.push_back(root->data);
}
void rightView(node *root, vector<int>&v) {
	if (root == NULL)return;
	v.push_back(root->data);
	rightView(root->right, v);

}
void topView(node *root, vector<int>&v) {

	leftView(root, v);
	rightView(root->right, v);

}

struct node * newNode(int data) {
	struct node * node = (struct node * ) malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);
}

int main() {

	struct node * root = newNode(10);
	root -> left = newNode(20);
	root -> left -> left = newNode(40);
	root -> right = newNode(30);
	root -> left -> right  = newNode(60);
	root -> right->right = newNode(100);
	root -> right -> left = newNode(90);
	vector < int > topview;
	topView(root, topview);
	for (auto it : topview) {
		cout << it << " ";
	}



}

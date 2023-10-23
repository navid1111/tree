#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int data;
	struct node *left , *right;

};
struct node * newNode(int data) {
	struct node * node = (struct node * ) malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);
}
node* searchBST(node * root, int data) {
	if (root != NULL && root->data != data) {
		{
			if (data < root->data)
				root = searchBST(root->left, data);
			else {
				root = searchBST(root->right, data);
			}
		}
	}
	return root;
}
int main() {

	struct node * root = newNode(8);
	root -> left = newNode(5);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(7);
	root -> left -> right -> left = newNode(6);
	root -> right = newNode(12);
	root -> right -> left = newNode(10);
	root -> right -> right = newNode(14);
	root -> right -> right ->left = newNode(13);

	node* found = searchBST(root, 14);

	if (found != NULL)
		cout << "Node value with given target found";
	else cout << "Node value with given target not found";

	return 0;
}
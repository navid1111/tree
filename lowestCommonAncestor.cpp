#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
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
node* findLowestAncestor(node *root, int p, int q) {

	if (root == NULL || root->data == p || root->data == q)return root;
	node * left = findLowestAncestor(root->left, p, q);
	node * right = findLowestAncestor(root->right, p, q);
	if (left == NULL)return right;
	else if (right == NULL)return left;
	else return root;

}
int main() {

	struct node * root = newNode(10);
	root -> left = newNode(20);
	root -> left -> left = newNode(30);
	root -> right = newNode(40);
	root -> left -> right  = newNode(50);
	root -> right->right = newNode(60);
	root -> right -> left = newNode(70);
	cout << findLowestAncestor(root, 20, 70)->data;



}
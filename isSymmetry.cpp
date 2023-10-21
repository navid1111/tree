#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int data;
	struct node *left , *right;

};
void rightcheck(node *root, vector<int>&v) {
	if (root == NULL)return;
	v.push_back(root->data);
	rightcheck(root->right, v);
	rightcheck(root->left, v);


}
void leftCheck(node *root, vector<int>&v) {
	if (root == NULL)return;
	v.push_back(root->data);
	leftCheck(root->left, v);
	leftCheck(root->right, v);


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
	root -> right = newNode(20);
	root -> left -> right  = newNode(60);
	root -> right->right = newNode(40);
	root -> right -> left = newNode(50);
	vector < int > left;
	vector < int > right;
	leftCheck(root->left, left);
	rightcheck(root->right, right);
	bool flag = true;
	if (left.size() != right.size()) {cout << "NO";}
	else {
		for (int i = 0; i < left.size(); i++) {
			if (left[i] != right[i]) {
				flag = false;
				break;
			}
		}
		if (flag == true)cout << "YES";
		else cout << "NO";
	}

}